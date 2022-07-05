import argparse
import ast

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('rulesfile')
    args = parser.parse_args()

    ops_table = {}
    with open(args.rulesfile) as f:
        for line in f.readlines():
            if 'applied' in line or '--' in line:
                continue
            ops = ast.literal_eval(line.strip())
            for op in ops:
                if op in ops_table:
                    ops_table[op] += 1
                else:
                    ops_table[op] = 1

    # Write out the table
    with open(args.rulesfile + '.table', 'w') as f:
        pairs = []
        for key in ops_table.keys():
            pairs.append((ops_table[key], key))
        spairs = []
        for (n, v) in sorted(pairs):
            spairs.append(str(n) + ", " + str(v))
        f.write('\n'.join(spairs))
