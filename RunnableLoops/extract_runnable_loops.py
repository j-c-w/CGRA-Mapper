#!/usr/bin/env python3.9

import argparse
import itertools
import re
import apsw
import shutil
import os

class Source():
    def __init__(self, source, runnable):
        self.source = source
        self.runnable = runnable
        self.source_hash = abs(hash(self.source))
        self.fname = "f" + str(self.source_hash)

mangle_num = 0
def mangle_name(n):
    global mangle_num

    mangle_num += 1
    return n + "_mangle_" + str(mangle_num)


seen_structs = set()

def rename_types(runnable_string):
    # Get any typedefs:
    matches = re.finditer('typedef.*?;', runnable);
    typedef_struct_matches = re.finditer('typedef struct[\s\S]*?}.*?;', runnable)
    
    # Get the struct defs too
    struct_matches = re.finditer('(^|\n)struct[\s\S]*?}.*?;', runnable);

    replaces = []

    for match in itertools.chain(matches, typedef_struct_matches):
        # Get the match string out (i.e. the typedef def)
        # -1 to get rid of the ';'
        match_string = runnable[match.start(0):match.end(0) - 1]
        defs = match_string.replace(' ', '\n').split('\n')
        name = defs[-1]
        original_name = defs[1]
        if '__' + name == original_name:
            # A bunch of defs seem to be unneeded.
            continue

        mangled_name = mangle_name(name)

        replaces.append((name, mangled_name))
        
    deletes = []
    for match in struct_matches:
        match_string = runnable[match.start(0):match.end(0)]
        name = match_string.split(' ')[-1]
        print("def is", name)

        # Delete any duplicate global structs --- need to not have too much memory
        # wasted to be able to run this on the small board.
        if name in seen_structs:
            deletes.append(match_string)
        else:
            seen_structs.add(name)

    for (name_from, name_to) in replaces:
        runnable_string = runnable_string.replace(name_from, name_to)
    for delete in deletes:
        runnable_string = runnable_string.replace(delete, '')

    return runnable_string

def fix_calls(runnable):
    # The extractor generates calls that look like this:
    # fn (..., x[500], ...) when x is an array of size 500 and 
    # fn sould take that aray as input.  Delete all the [ and ] in the
    # call.
    calls = re.finditer('fn\(.*?\)', runnable)
    found = 0
    for call in calls:
        found += 1
        call_contents = runnable[call.start(0):call.end(0)]
        start = call.start(0)
        end = call.end(0)

    if found != 1:
        #must have one call.
        print("No call found in ", runnable)
        assert False

    # Find all matches within the call contents
    array_index_matches = re.finditer('\[.*?\]', call_contents)
    deletes = []
    for match in array_index_matches:
        deletes.append(call_contents[match.start(0):match.end(0)])
    for d in deletes:
        call_contents = call_contents.replace(d, '')

    # Splice modifed call back in
    runnable = runnable[:start] + call_contents + runnable[end:]

    return runnable

def fix_defs(runnable):
    runnable = re.replace('\[1024\] = ', '[2048] =', runnable)

def assign_const_ints(runnable):
    const_assigns = re.finditer('const int [a-zA-Z0-9_]*?;', runnable)
    replace_texts = []

    for match in const_assigns:
        match_test = runnable[match.start(0):match.end(0)]

        replace_texts.append(match_test)

    for replacable in replace_texts:
        new_text = replacable.replace(';', ' = 32;')
        runnable = runnable.replace(replacable, new_text)

    return runnable

def insert_running_loop(runnable):
    # Find the START and END points --- we insert a loop between those.
    startpoint = re.finditer("START.*?;\n", runnable)
    endpoint = re.finditer("END", runnable)

    # Pre-code:
    pre_loop = """int __FlexCLoopCounter = 0;
    for (; __FlexCLoopCounter < TIMES; __FlexCLoopCounter ++) {
    """
    post_loop = "\n}\n"

    # Now, splice together
    starts = 0
    for match in startpoint:
        starts += 1
        start = match.end(0)

    ends = 0
    for match in endpoint:
        ends += 1
        end = match.start(0)

    if not(starts == 1 and ends == 1):
        print("Runnable, ", runnable, "donens't have right number of starts and ends")
        assert False

    call_contents = runnable[start:end]

    return runnable[:start] + pre_loop + call_contents + post_loop + runnable[end:]

def cast_arguments_to_void(runnable):
    funcall = re.finditer('fn\(.*?\)[^\[]', runnable)
    matches = 0
    for match in funcall:
        matches += 1
        funcall_string = runnable[match.start(0) + 3:match.end(0) - 2]

    if matches != 1:
        print ("Runnable", runnable, "has too many matches")
        assert False

    fundef = re.finditer('fn \([\s\S]*?\)[^\[]', runnable)
    defmatches = 0
    for defmatch in fundef:
        defmatches += 1
        fundef_string = runnable[defmatch.start(0):defmatch.end(0) - 1]

    if defmatches != 1:
        print("Def maches is none on ", runnable)
        assert False

    # Get the types of every def --- it's all but the last word (including '*' if that eists)
    fundef_string = fundef_string[4:-1] # drop fn ( and )
    vardefs = fundef_string.split(',')
    cast_types = []
    for vardef in vardefs:
        if 'e_curr' in vardef:
            # There ecurr types have weird formatting -- skip.
            cast_types.append(None)
            continue
        vardef = vardef.replace('*', '* ')
        type = ' '.join(vardef.split(' ')[:-1])
        cast_types.append(type.strip())

    # split by args.
    funcall_string = funcall_string.replace(',', ' ').split(' ')
    # filter out empties
    funcall_args = [ff for ff in funcall_string if ff]

    # everything but first is a funarg.
    cast_args = []
    i = 0
    for arg in funcall_args:
        if cast_types[i]:
            cast_args.append('(' + cast_types[i] + ')' + arg)
        else:
            cast_args.append(arg)
        i += 1

    newcall = "fn(" + ", ".join(cast_args) + ");"

    return runnable[:match.start(0)] + newcall + runnable[match.end(0):]


def fix_broken_const_assignments(runnable):
    const_assignments = re.finditer('const .*?\[.*?\].*?[=;]', runnable)
    to_swap = []
    for match in const_assignments:
        string = runnable[match.start(0):match.end(0)]
        values = string.replace(';', ' ;').split(' ')
        if len(values) == 3:
            new_string = 'const int ' + ''.join(values[1:])
            to_swap.append((string, new_string.replace(' ;', ';')))
        
    for (swap_from, swap_to) in to_swap:
        runnable = runnable.replace(swap_from, swap_to)

    return runnable


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('db', help='db file name')
    parser.add_argument('output_folder', help='output folder for loops')

    args = parser.parse_args()

    con = apsw.Connection(args.db)
    cur = con.cursor()

    counter = 0
    if os.path.exists(args.output_folder):
        shutil.rmtree(args.output_folder)

    os.mkdir(args.output_folder)
    os.mkdir(args.output_folder + '/loops')

    sources = []
    for s in cur.execute("""
        select loops.src, loops.src_with_call from loops
        where clang_returncode is 0
        and loops.meta_stmt_counts_IfStmt is null and
        loops.meta_stmt_counts_CallExpr is null and
        loops.clang_and_run_returncode is 0    """):
        source = s[0]
        runnable = s[1]

        sources.append(Source(s[0], s[1]))

    loops_string = ""
    runfuns = []
    imports = set()
    imports.add('#include "../utils.h"')
    used_fnames = set()

    for loop in sources:
        runnable = loop.runnable
        # There are some dups in the set.
        # Dont' need to measure those twice.
        if loop.fname in used_fnames:
            continue
        else:
            used_fnames.add(loop.fname)

        # Avoid redfined structs and loops.
        runnable = rename_types(runnable)

        # There are some issues in the loop extractor when generating calls to fixed-length
        # arrays --- fix those.
        runnable = fix_calls(runnable)
        runnable = assign_const_ints(runnable)

        # embedded armcc doesn't support this apparently.
        runnable = runnable.replace('__restrict', ' ')

        # Alex's code is a bit broken: try and fix it up here with void* casts and -fpermissive.
        # needs ot happen befoer the fn( replacement.
        runnable = cast_arguments_to_void(runnable)
        # Alex's code is also a bit broken here: for const inputs it doesn't generate
        # everything.
        runnable = fix_broken_const_assignments(runnable)

        # We do some rewriting to the runnable one for tracking.
        runnable = runnable.replace('fn (', loop.fname + ' (')
        runnable = runnable.replace('fn(', loop.fname + '(')

        runnable = runnable.replace(loop.fname + '(', 'START("' + str(loop.source_hash) + '");\n' + loop.fname + '(')
        runnable = runnable.replace('return 0;\n}', 'END("' + str(loop.source_hash) + '"); return 0;\n}')

        # Custom function name:
        runnable = runnable.replace('int main()', 'int run_' + loop.fname + '()')
        runfuns.append('run_' + loop.fname)

        # Remove imports to top.
        for line in runnable.split('\n'):
            if line.startswith("#include"):
                imports.add(line)
        runnable = re.sub('#include.*?\n', '', runnable)


        # add #define to track how many times the loop executed.
        insert_index = re.finditer('for (.*)[ \t\n]*?{', runnable)
        match_found = False
        for match in insert_index:
            match_found = True
            # Insert the 'define after end.
            end = match.end(0)
            runnable = runnable[0:end] + "\nLOOP_ITERATION;\n" + runnable[end:]

        if not match_found:
            no_body_loop = re.finditer('for ([^\n]*);', runnable)
            for match in no_body_loop:
                print("Simple loop ", runnable[match.start(0):match.end(0)], "skipped")
                match_found = True

            # Skip this loop -- it's of format for(....); and that is it.
            del runfuns[-1]
            continue

        if not match_found:
            # For single-line loops, it generates:
            # for (...)
            #   code
            # We need to do more complex substitution.
            insert_index = re.finditer('for ([^\n]*)\n', runnable)
            tail_insert_index = re.finditer('for ([^\n]*)\n.*?\n', runnable)
            for match in insert_index:
                end = match.end(0)
                runnable = runnable[:end] + "{\nLOOP_ITERATION;\n" + runnable[end:]
            for match in tail_insert_index:
                end = match.end(0)
                runnable = runnable[:end] + ";}" + runnable[end:]

        # Insert a running loop to allow this to be run mnay times.  Note that this has
        # to happen last --- otherwise it will interfere with the other stuff here.
        runnable = insert_running_loop(runnable)

        # Write the loop individually into a matched source
        # file so we can get the CGRA-Mapper compile time.
        with open(args.output_folder + '/loops/' + str(loop.source_hash) + '.c', 'w') as f:
            f.write(loop.source)

        loops_string += "\n" + runnable + "\n"

    # Add a main function and imports to the loops_string
    imports = "\n".join(imports)
    runfuns = [runfun + "();" for runfun in runfuns]
    mainfun = "int main() {\n" + "\n".join(runfuns) + "\n}"

    with open(args.output_folder + '/runnable.c', 'w') as f:
        f.write(imports + loops_string + mainfun)

