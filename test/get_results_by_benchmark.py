import argparse

# Add to a dict
def add(d, v):
    if v in d:
        d[v] += 1
    else:
        d[v] = 1

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("LoopName") # Just for insertion into the result csv
    parser.add_argument("InputFile")
    parser.add_argument("OutputFile")

    args = parser.parse_args()

    # This file contains a bunch of junk,
    # followed by a bunch of lines
    # like:
    # [Mapping:success]
    # File Done: <fname>
    # or
    # [Mapping:fail]
    # File Done: <fname>
    # We turn this into a dict of
    # <benchmark_name>: successes and fails
    with open(args.InputFile) as f:
        success = False
        fail = False

        successes_dict = {}
        fails_dict = {}

        for line in f.readlines():
            if "Mapping:success" in line:
                success = True
            if "Mapping:fail" in line:
                fail = True
            if "Done File" in line:
                fname = line.split(':')[1]
                bname = fname.split('_')[2] # at 2 because the script prefixes kernel_ onto things
                if success:
                    add(successes_dict, bname)
                    success = False
                if fail:
                    add(fails_dict, bname)
                    fail = False

    # Now, do the output of this
    with open(args.OutputFile, 'a') as f:
        # We do this not as a true CSV because it's possible 
        # (although it shouldn't happen) that not all benchmarks
        # will be there for each run.
        string = args.LoopName

        for key in successes_dict:
            string += ",success:" + key + ":" + str(successes_dict[key])
        for key in fails_dict:
            string += ",fail:" + key + ":" + str(fails_dict[key])

        f.write(string + "\n")