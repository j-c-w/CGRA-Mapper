import argparse
import matplotlib.pyplot as plt
import numpy as np

labels = ['freeimage', 'ffmpeg', 'DarkNet', 'LivermoreC', 'bzip2']

def name_from_file(f):
    splitup = f.split('_')
    if len(splitup) > 1:
        return splitup[1]
    else:
        # We also use this script in the case studies, where _ may
        # not exist.
        return splitup[0]

# Line format (see get_results_by_benchmark.py)
# is fname,success:bname:N,...,fail:bnameX:M,...

# this returns a dict of dicts, where the outer dict
# contains each of the benchmarks run, and the inner
# dict contains each ofht individual results.
# Done in this way so we can change what we are plotting.
def load_from_file(f):
    succ_dict = {}
    fail_dict = {}

    with open(f) as f:
        for line in f.readlines():
            print("Loading line ", line)
            line = line.split(",")
            fname_source = line[0]
            # Go over every sub-part to that thing.
            succ_dict[fname_source] = {}
            fail_dict[fname_source] = {}
            for elem in line[1:]:
                elem = elem.split(":")
                mode = elem[0] # success or fail
                bname = elem[1] # a benchmark suite name
                num = int(elem[2].strip()) # how many benchmarks did this thing.

                if mode == "success":
                    succ_dict[fname_source][bname] = num
                elif mode == "fail":
                    fail_dict[fname_source][bname] = num
                else:
                    print (mode)
                    assert False # Needs to be success or fail.
    return succ_dict, fail_dict


#given these two oddly formatted dicts, computes a single
# dict that is:
# { 'bmark': {'subbmark': rate, ...}}
# Where this means accelerators for loops in bmark, targted by accelerators
# in loop 'subbmark' had success rate rate.
def load_in_vs_out_of_benchmark_compiles(succ_dict, fail_dict):
    res_dict = {}

    all_keys = set()
    for fname in succ_dict:
        all_keys = all_keys.union(set(list(succ_dict[fname].keys()) + list(fail_dict[fname].keys())))
    print (succ_dict)
    print (fail_dict)
    print ("all keys is ", all_keys)
    for fname in succ_dict: # guarnateed to have same keys
        bname = name_from_file(fname)
        if bname not in res_dict:
            res_dict[bname] = {}
            for key in all_keys:
                res_dict[bname][key] = []

        for sub_bname in all_keys:
            print("Looking at ", sub_bname, fname)
            if sub_bname in succ_dict[fname]:
                succs = succ_dict[fname][sub_bname]
            else:
                succs = 0
            print(bname, "have ", succs, 'succs')
            if sub_bname in fail_dict[fname]:
                fails = fail_dict[fname][sub_bname]
            else:
                fails = 0

            if succs == 0 and fails == 0:
                print("Warning: both are zero, skipping ", fname)
                continue
            res_value = float(succs) / (float(succs + fails))
            res_dict[bname][sub_bname].append(res_value)
            print(res_value)

    # Now, go through thre res dict list and turn those into
    # average success rates.
    for n in res_dict:
        for b in res_dict[n]:
            # Intentionally break this mean up into two different means.
            # This way we don't over-report the large benchmark
            # suite for image processing.
            if len(res_dict[n][b]) == 0:
                print("No builds for ", n, b)
                res_dict[n][b] = 0.0
            else:
                res_dict[n][b] = np.mean(res_dict[n][b])
    return res_dict

def get_series_from_dict(d):
    same_series = []
    diff_series = []
    xlabs = []
    global labels
    for key in labels:
        diffs = []
        xlabs.append(key)
        for elem in d[key]:
            print(key, elem)
            value = d[key][elem]
            if key == elem:
                same_series.append(value)
            else:
                diffs.append(value)
        diff_series.append(np.mean(np.array(diffs)))
    return same_series, diff_series

# Plot a simple bar chart specifying whether things are in
# the same benchmark suite or a differnet one.
def plot_same_and_different(baseline_dict, rewriter_dict, outname):
    # One x value for each key,
    # then one series for each entry within
    # that.
    same_series_baseline, diff_series_baseline = get_series_from_dict(baseline_dict)
    same_series_rewriter, diff_series_rewriter = get_series_from_dict(rewriter_dict)

    width = 0.15
    global labels
    xvals = np.arange(0, len(labels))
    print("Have labels", labels)
    print("Same series is (baseline)", same_series_baseline)
    print("Different series is (baseline)", diff_series_baseline)
    plt.bar(xvals - width * 1.7, diff_series_baseline, hatch='x', color='#818fa6', label="OpenCGRA: Other Suites", width=width)
    plt.bar(xvals - width * 0.7, same_series_baseline, hatch='x', color='#c99083', label="OpenCGRA: Same Suite", width=width)
    plt.bar(xvals + width * 0.7, diff_series_rewriter, hatch='.', color='#818fa6', label="FlexC: Other Suites", width=width)
    plt.bar(xvals + width * 1.7, same_series_rewriter, hatch='.', color='#c99083', label="FlexC: Same Suite", width=width)
    plt.gca().set_xticklabels([''] + labels) #not sure why we have to do this.
    plt.gca().set_ylabel("Fraction of Loops Compiled to Accelerator")
    plt.gca().set_xlabel("Benchmark Suite Original Accelerator was Selected From")
    plt.ylim([0, 1])
    plt.legend()
    plt.savefig(outname + '_basic.eps')
    plt.savefig(outname + '_basic.png')


if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("output_filename")
    parser.add_argument("input_filename_baseline")
    parser.add_argument("input_filename_rewriter")

    args = parser.parse_args()

    s_dict, f_dict = load_from_file(args.input_filename_rewriter)
    # see comment on below function for documentation.
    rewriter_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict)

    s_dict, f_dict = load_from_file(args.input_filename_baseline)
    baseline_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict)

    plot_same_and_different(baseline_dict, rewriter_dict, args.output_filename)