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

# Skip these as they crash.  Don't know wy they aren't picked up by Alex's tool.
skips = [
        "f4950273923585529084",
        "f1668337996997030710"
        ]

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
    used_fnames = set()

    for loop in sources:
        runnable = loop.runnable
        if loop.fname in skips:
            # Skip that thing too.
            continue
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

        # We do some rewriting to the runnable one for tracking.
        runnable = runnable.replace('fn (', loop.fname + ' (')
        runnable = runnable.replace('fn(', loop.fname + '(')

        runnable = runnable.replace(loop.fname + '(', 'START("' + str(loop.source_hash) + '");\n' + loop.fname + '(')
        runnable = runnable.replace('return 0;', 'END("' + str(loop.source_hash) + '"); return 0;')

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

