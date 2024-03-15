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

    con = apsw.Connection(args.db)
    cur = con.cursor()

    counter = 0
    if os.path.exists(args.output_folder):
        shutil.rmtree(args.output_folder)
    os.mkdir(args.output_folder)

    count = 0
    for s in cur.execute("""
    select * from (
            select loops.src, loops.filename, loops.meta_project, loops.rowid, ROW_NUMBER() OVER(PARTITION BY loops.body ORDER BY loops.rowid DESC) rn
            from loops
            where loops.meta_clang_returncode is 0 and loops.meta_project != 'libav'
            ) a
    where rn = 1"""):
        count += 1
    print("Total count is ", count)
    # Get the non-duplicate loops out.
    for s in cur.execute("""
    select * from (
            select loops.src, loops.filename, loops.meta_project, loops.rowid, ROW_NUMBER() OVER(PARTITION BY loops.body ORDER BY loops.rowid DESC) rn
            from loops
            where loops.meta_clang_returncode is 0 and loops.meta_stmt_counts_IfStmt is null and loops.meta_stmt_counts_CallExpr is null and loops.meta_project != 'libav'
            ) a
    where rn = 1"""):
        project = s[2]
        rowid = s[3]

        with open(args.output_folder + "/loop_" + project + "_" + str(counter) + ".c", 'w') as f:
            program = s[0]
            file = s[1]
            f.write('// Source is: ' + file + '\n\n' + program)
        counter += 1

    print("Accelerated count is ", counter)
