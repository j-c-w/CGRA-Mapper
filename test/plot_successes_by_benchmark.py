import argparse
import matplotlib.pyplot as plt
import numpy as np
import statistics

colors=['#818fa6', '#6ea5ff', '#95c983', '#c99083', '#e079d6']
hatching=['O', 'o', '.', '..', '-', 'x']

labels = ['freeimage', 'ffmpeg', 'DarkNet', 'LivermoreC', 'bzip2']

def name_from_file(f):
    splitup = f.split('_')
    if len(splitup) > 1:
        return splitup[1]
    else:
        # We also use this script in the case studies, where _ may
        # not exist.
        return splitup[0]

def load_size_dict(f):
    #TODO
    pass

# Line format (see get_results_by_benchmark.py)
# is fname,success:bname:N,...,fail:bnameX:M,...

# this returns a dict of dicts, where the outer dict
# contains each of the benchmarks run, and the inner
# dict contains each ofht individual results.
# Done in this way so we can change what we are plotting.

# We can also plot the same graph, but by the number of operations
# availbale on the CGRA rather than the benchmark name.
# To do this, a map from the kernel name to the number of operations
# should be provided.  That is loaded by a the load_size_dict() function.
def load_from_file(f, by_size, size_lookup={}):
    succ_dict = {}
    fail_dict = {}

    with open(f) as f:
        for line in f.readlines():
            line = line.split(",")
            fname_source = line[0].split(':')[0]
            size_acc = int(line[0].split(':')[1])
            # Load eitehr by the benchmark suite or
            # the size of the accelerator
            if by_size:
                base_key = size_acc
                lookup_name = ''.join(fname_source.split('.')[:-1]) #These have a .mode on the end that we mmorev
                if size_acc == 0 and lookup_name in size_lookup:
                    # Due to crappy scripts, the size isn't recoreded
                    # in the non-egraphs node (actually it's a missing
                    # print in FlexC).
                    # To make up for that, we load with a dict
                    # that maps filename to size.
                    base_key = size_lookup[lookup_name]
                elif size_acc > 0:
                    size_lookup[lookup_name] = size_acc
            else:
                base_key = fname_source

            # Go over every sub-part to that thing.
            if base_key not in succ_dict:
                succ_dict[base_key] = {}
                fail_dict[base_key] = {}
            for elem in line[1:]:
                elem = elem.split(":")
                mode = elem[0] # success or fail
                bname = elem[1] # a benchmark suite name
                num = int(elem[2].strip()) # how many benchmarks did this thing.

                if mode == "success":
                    if bname in succ_dict[base_key]:
                        succ_dict[base_key][bname] += num
                    else:
                        succ_dict[base_key][bname] = num
                elif mode == "fail":
                    if bname in fail_dict[base_key]:
                        fail_dict[base_key][bname] += num
                    else:
                        fail_dict[base_key][bname] = num
                else:
                    print (mode)
                    assert False # Needs to be success or fail.
    return succ_dict, fail_dict, size_lookup


#given these two oddly formatted dicts, computes a single
# dict that is:
# { 'bmark': {'subbmark': rate, ...}}
# Where this means accelerators for loops in bmark, targted by accelerators
# in loop 'subbmark' had success rate rate.
def load_in_vs_out_of_benchmark_compiles(succ_dict, fail_dict, by_size):
    res_dict = {}

    all_keys = set()
    for fname in succ_dict:
        all_keys = all_keys.union(set(list(succ_dict[fname].keys()) + list(fail_dict[fname].keys())))
    # print ("all keys is ", all_keys)
    for fname in succ_dict: # guarnateed to have same keys
        if by_size:
            bname = fname
        else:
            bname = name_from_file(fname)
        if bname not in res_dict:
            res_dict[bname] = {}
            for key in all_keys:
                res_dict[bname][key] = []

        for sub_bname in all_keys:
            # print("Looking at ", sub_bname, fname)
            if sub_bname in succ_dict[fname]:
                succs = succ_dict[fname][sub_bname]
            else:
                succs = 0
            # print(bname, "have ", succs, 'succs')
            if sub_bname in fail_dict[fname]:
                fails = fail_dict[fname][sub_bname]
            else:
                fails = 0

            if succs == 0 and fails == 0:
                print("Warning: both are zero, skipping ", fname)
                continue
            res_value = float(succs) / (float(succs + fails))
            res_dict[bname][sub_bname].append(res_value)
            # print(res_value)

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
    # print("Same series is (baseline)", same_series_baseline)
    # print("Different series is (baseline)", diff_series_baseline)
    plt.bar(xvals - width * 1.7, diff_series_baseline, hatch='x', color='#818fa6', label="OpenCGRA: Other Suites", width=width)
    plt.bar(xvals - width * 0.7, same_series_baseline, hatch='x', color='#c99083', label="OpenCGRA: Same Suite", width=width)
    plt.bar(xvals + width * 0.7, diff_series_rewriter, hatch='.', color='#818fa6', label="FlexC: Other Suites", width=width)
    plt.bar(xvals + width * 1.7, same_series_rewriter, hatch='.', color='#c99083', label="FlexC: Same Suite", width=width)
    plt.gca().set_xticklabels([''] + labels) #not sure why we have to do this.
    plt.gca().set_ylabel("Fraction of Loops Compiled to Accelerator")
    plt.gca().set_xlabel("Benchmark Suite Original Accelerator was Selected From")
    plt.text(-width * 1.7, 0.4, 'OpenCGRA', rotation=90)
    plt.text(-width * 2.8, 0.35, '}', size=30, rotation=90)
    plt.text(+width * 0.7, 0.5, 'FlexC', rotation=90)
    plt.text(-width * 0.5, 0.45, '}', size=30, rotation=90)
    plt.ylim([0, 1])
    plt.legend()
    plt.savefig(outname + '_basic.eps')
    plt.savefig(outname + '_basic.png')
    same_suite_improvements = []
    for i in range(len(same_series_baseline)):
        same_suite_improvements.append(same_series_rewriter[i] / same_series_baseline[i])
    diff_suite_improvements = []
    for i in range(len(same_series_baseline)):
        diff_suite_improvements.append(diff_series_rewriter[i] / diff_series_baseline[i])
    print("Geomean within same suite is " + str(statistics.geometric_mean(same_suite_improvements)))
    print("Geomean between suites is " + str(statistics.geometric_mean(diff_suite_improvements)))

def plot_from_size(baseline_dict, llvm_dict, greedy_dict, rewriter_dict, outname):
    def average_dict(d):
        newd = {}
        for k in d:
            if k == 0:
                continue # Some loops fail all together.
            vs = []
            for k2 in d[k]:
                vs.append(d[k][k2])
            newd[k] = np.mean(vs)
        xs = np.array(sorted(newd.keys()))
        ys = np.array([newd[x] for x in xs])
        return xs, ys

    base_x, base_y = average_dict(baseline_dict)
    llvm_x, llvm_y = average_dict(llvm_dict)
    greedy_x, greedy_y = average_dict(greedy_dict)
    xs, ys = average_dict(rewriter_dict)
    xvalues = np.arange(min(xs), max(xs) + 1)
    base_xvalues = np.arange(min(base_x), max(base_x) + 1)
    base_greedy_values = np.arange(min(greedy_x), max(greedy_x) + 1)

    plt.clf()
    # print(len(xvalues))
    # print(len(ys))
    width=0.20
    plt.bar(base_xvalues-width*1.5, base_y, label='OpenCGRA', width=width, color=colors[0], hatch=hatching[0])
    plt.bar(llvm_x-width*0.5, llvm_y, label='LLVM', width=width, color=colors[1], hatch=hatching[1])
    plt.bar(greedy_x+width*0.5, greedy_y, label='Greedy Rewriter', width=width, color=colors[2], hatch=hatching[2])
    plt.bar(xvalues+width*1.5, ys, label='FlexC', width=width, color=colors[3], hatch=hatching[3])
    plt.legend()
    plt.gca().set_xticks(xvalues)
    plt.gca().set_xticklabels([str(x) for x in xs]) #not sure why we have to do this.
    plt.xlabel("Number of Different Operations Supported by Accelerator")
    plt.ylabel("Compilation Rate")
    plt.savefig(outname + '_by_size.png')
    plt.savefig(outname + '_by_size.eps')

    print("Done with by size graph (in " + outname + '_by_size.png)')

def plot_case_studies_graph(outname, opencgra, llvm, greedy, flexc):
    architectures = ["CCA", "Maeri", "REVAMP", "SC-CGRA"]
    bmarks = ["LivermoreC", "DarkNet", "ffmpeg", "bzip2", "freeimage"]

    plt.clf()
    # First, we want to build the relevant series.
    fig, ax = plt.subplots(1, 4, figsize=(12, 3))

    # REeturn the y values in a consistent order
    def y_values_for(d):
        ys = []
        for b in bmarks:
            ys.append(d[b])
        return ys

    for i in range(4): # one for each arch.
        arch = architectures[i]
        opencgra_data = opencgra[arch]
        llvm_data = llvm[arch]
        greedy_data = greedy[arch]
        flexc_data = flexc[arch]
        xpoints = np.arange(len(bmarks))
        width = 0.15

        ax[i].set_title(arch)
        ax[i].bar(xpoints - 1.5 * width, y_values_for(opencgra_data), width=width, label='OpenCGRA', color=colors[0], hatch=hatching[0])
        ax[i].bar(xpoints - 0.5 * width, y_values_for(llvm_data), width=width, label='LLVM', color=colors[1], hatch=hatching[1])
        ax[i].bar(xpoints + 0.5 * width, y_values_for(greedy_data), width=width, label='Greedy', color=colors[2], hatch=hatching[2])
        ax[i].bar(xpoints + 1.5 * width, y_values_for(flexc_data), width=width, label='FlexC', color=colors[3], hatch=hatching[3])
        ax[i].set_ylim([0, 1.0])
        ax[i].set_xticks(xpoints)
        ax[i].set_xticklabels(bmarks, rotation=90)
        if i == 1:
            ax[i].legend(ncol=1, prop={'size': 9})

    plt.tight_layout()
    plt.savefig(outname + "_case_studies_by_benchmark.png")
    plt.savefig(outname + "_case_studies_by_benchmark.eps")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument("output_filename")
    parser.add_argument("input_filename_baseline")
    parser.add_argument("input_filename_llvm")
    parser.add_argument("input_filename_greedy", help="Not currently used in loop-on-loop case")
    parser.add_argument("input_filename_rewriter")
    parser.add_argument("--case-studies", default=False, action='store_true', dest='case_studies')

    args = parser.parse_args()

    if args.case_studies:
        s_dict, f_dict, _ = load_from_file(args.input_filename_rewriter, False)
        rewriter_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, False)

        s_dict, f_dict, _ = load_from_file(args.input_filename_llvm, False)
        llvm_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, False)

        s_dict, f_dict, _ = load_from_file(args.input_filename_greedy, False)
        greedy_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, False)

        s_dict, f_dict, _ = load_from_file(args.input_filename_baseline, False)
        baseline_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, False)

        plot_case_studies_graph(args.output_filename, baseline_dict, llvm_dict, greedy_dict, rewriter_dict)
    else:
        # Plot the results by benchmark suite.
        s_dict, f_dict, _ = load_from_file(args.input_filename_rewriter, False)
        # see comment on below function for documentation.
        rewriter_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, False)

        s_dict, f_dict, _ = load_from_file(args.input_filename_llvm, False)
        llvm_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, False)

        s_dict, f_dict, _ = load_from_file(args.input_filename_baseline, False)
        baseline_dict = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, False)

        plot_same_and_different(baseline_dict, rewriter_dict, args.output_filename)

        # Plot the results by benchmark suite.
        s_dict, f_dict, size_lookup = load_from_file(args.input_filename_rewriter, True)
        print('dict is ', size_lookup)
        rewriter_dict_by_size = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, True)
        s_dict, f_dict, _ = load_from_file(args.input_filename_llvm, True, size_lookup)
        llvm_dict_by_size = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, True)
        s_dict, f_dict, _ = load_from_file(args.input_filename_greedy, True, size_lookup)
        greedy_dict_by_size = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, True)
        s_dict, f_dict, _ = load_from_file(args.input_filename_baseline, True, size_lookup)
        baseline_dict_by_size = load_in_vs_out_of_benchmark_compiles(s_dict, f_dict, True)

        print("By size is", rewriter_dict_by_size)
        print("orig is ", baseline_dict_by_size)
        plot_from_size(baseline_dict_by_size, llvm_dict_by_size, greedy_dict_by_size, rewriter_dict_by_size, args.output_filename)
