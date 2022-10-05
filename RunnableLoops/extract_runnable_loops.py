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
    """):
        source = s[0]
        runnable = s[1]

        sources.append(Source(s[0], s[1]))

    loops_string = ""
    runfuns = []
    imports = set()

    for loop in sources:
        runnable = loop.runnable
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
        for match in insert_index:
            # Insert the 'define after end.
            end = match.end(0)
            runnable = runnable[0:end] + "\nLOOP_ITERATION;\n" + runnable[end:]

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

