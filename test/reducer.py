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
        return nam
    except:
        # For backwards compatability --- previous versions
        # did not distinguish by suite.
        # Note that the performace graph doens't do this either
        # due to the hashing approach
        print("Warning: no benchmark suite found", file=sys.stderr)
        return ""

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    # Two modes --- either reduce to a particular fraction of benchmarks or
    # to a praticular number of benchmarks
    parser.add_argument('--rate', dest="reduction_rate", type=float, default=None)
    parser.add_argument('--number', dest='number', type=int, default=None)
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
        if args.reduction_rate:
            new_num = int(len(by_suite[n]) * args.reduction_rate)
        elif args.number:
            # Divy up equally between architectures.
            new_num = int(args.number // len(by_suite))
            if new_num > len(by_suite[n]):
                # Can't go beyond the end of the benchmark suite however.
                # We choose not to make this up --- this is a fuzzy
                # tool to help reduce the computation power required :)
                new_num = len(by_suite[n])
        else:
            print ("Must have one of number or reduction rate set")
            assert False # Need to have one

        if new_num == 0:
            new_num = 1
        
        # Random, but repeatable shuffle.
        random.shuffle(by_suite[n])
        end_suite[n] = by_suite[n][:new_num]

    # Print out the benchmark suites
    for n in end_suite:
        for e in end_suite[n]:
            print(e + " ", end='')
