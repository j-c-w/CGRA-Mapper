#!/usr/bin/env python3

import argparse
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
        where meta_clang_returncode is 0
        and loops.meta_stmt_counts_IfStmt is null and
        loops.meta_stmt_counts_CallExtr is null and
        loops.meta_project != 'libav'
    """):
        source = s[0]
        runnable = s[1]

        sources.append(Source(s[0], s[1]))

    loops_string = ""
    runfuns = []
    imports = set()
    used_fnames = set()

    for loop in sources:
        runnable = loop.runnable
        # There are some dups in the set.
        # Dont' need to measure those twice.
        if loop.fname in used_fnames:
            continue
        else:
            used_fnames.add(loop.fname)

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
            # For single-line loops, it generates:
            # for (...)
            #   code
            # We need to do more complex substitution.
            insert_index = re.finditer('for ([^\n]*)\n', runnable)
            tail_insert_index = re.finditer('for ([^\n])\n.*?\n', runnable)
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
    mainfun = "int main() {" + "\n".join(runfuns) + "}"

    with open(args.output_folder + '/runnable.c', 'w') as f:
        f.write(imports + loops_string + mainfun)

