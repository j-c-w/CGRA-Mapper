#!/usr/bin/env python3

import argparse
import apsw
import shutil
import os

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('db', help='db file name')
    parser.add_argument('output_folder', help='output folder for loops')

    args = parser.parse_args()

    con = apsw.Connection('loops.db')
    cur = con.cursor()

    counter = 0
    if os.path.exists(args.output_folder):
        shutil.rmtree(args.output_folder)
    os.mkdir(args.output_folder)
    for s in cur.execute('select body from loops'):
        with open(args.output_folder + "/loop" + str(counter) + ".c", 'w') as f:
            program = s[0]
            file = "TODO --- get source filename" # s[1]
            f.write('// Source is: ' + file + '\n\n' + program)
        counter += 1