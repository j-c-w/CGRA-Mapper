import argparse
import random
import sys

random.seed(0)
# Take a list of files of the format loop_NAME_Number.c
# and produce a deterministic, reduced list of those
# files where each NAME is represented proportionally
# (each NAME) is a benchmark suite.

def get_name(f):
    try:
        nam =  f.split('_')[1]
    except:
        # For backwards compatability --- previous versions
        # did not distinguish by suite.
        print("Warning: no benchmark suite found", file=sys.stderr)
        return ""

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("reduction_rate", type=float)
    parser.add_argument("files", nargs='+')

    args = parser.parse_args()

    by_suite = {}
    # Sort before shuffle to make this deterministic regardless of input order
    for f in sorted(args.files):
        name = get_name(f) # Get benchmark suite name
        if name in by_suite:
            by_suite[name].append(f)
        else:
            by_suite[name] = [f]

    # Now reduce -- keetp at least one in each to make
    # the other scirpts easier.
    end_suite = {}
    for n in by_suite:
        new_num = int(len(by_suite[n]) * args.reduction_rate)
        if new_num == 0:
            new_num = 1
        
        # Random, but repeatable shuffle.
        random.shuffle(by_suite[n])
        end_suite[n] = by_suite[n][:new_num]
        print("Reduced to ", len(end_suite[n]), "newnum", new_num)

    # Print out the benchmark suites
    for n in end_suite:
        for e in end_suite[n]:
            print(e + " ", end='')
