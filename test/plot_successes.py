import matplotlib.pyplot as plt
import numpy as np
import argparse
import statistics

def load_from_file(f):
    res = {}
    with open(f) as f:
        for line in f.readlines():
            line = line.split(',')
            bname = line[0]
            if line[1].strip() != '':
                succs = int(line[1])
            else:
                succs = 0 # TODO -- should we indicate failure in a clearer way?
            res[bname] = succs
    return res

rewriter_modes_labels = ['OpenCGRA', 'Greedy', 'FlexC']
rulesets_labels = ['Integer', 'Floating Point', 'Logic as Boolean', 'All']
styles = ['--', '-.', ':', '-']
def plot_line_from_dicts(labels, tname, dicts, plotting_rulesets):
    zipped_lines = {}
    first_dsize = len(dicts[0])
    for d in dicts:
        print(d)
        print(len(d))
        dsize = len(d)
        assert dsize == first_dsize # If these are different, something failed e.g. with eggraphs that didn't fail without it 
        # They should both be equally excluded at a previous stage (since if egraphs fails we just won't use it and
        # can assume unchanged support --- really going to be due to bugs rather than fundamental issues though.)
        # TODO -- we could probably support that in this graph anyway?
        for k in d.keys():
            new_k = k.split('.')[0] # Stupid hack to get rid of trailing notes that include the method used to get this number
            if new_k in zipped_lines:
                zipped_lines[new_k].append(d[k])
            else:
                zipped_lines[new_k] = [d[k]]

    print("Before, length of zipped lines is ", len(zipped_lines))
    # If every entry is 0, it's probably vecause tghe benchmark
    # wasn't actually run -- delete it to allow for debugging w/out
    # running everything.
    for i in list(zipped_lines.keys()):
        all_zero = True
        for elem in zipped_lines[i]:
            all_zero = all_zero and (elem == 0)

        if all_zero:
            del zipped_lines[i]
    print("Afterwards, length of zipped lines is ", len(zipped_lines))

    # Now, sort that dict by magnitude of the first element, 
    # and unzip.
    if not plotting_rulesets:
        improvements = [float(zipped_lines[k][2]) / float(zipped_lines[k][0]) for k in zipped_lines if zipped_lines[k][0] > 0 and zipped_lines[k][2] > 0]
    unsortedd_and_zipped = [zipped_lines[k] for k in zipped_lines]
    sorted_and_zipped = sorted(unsortedd_and_zipped)
    lines = [[] for i in range(len(sorted_and_zipped[0]))]
    for i in range(len(sorted_and_zipped)):
        for j in range(len(sorted_and_zipped[i])):
            lines[j].append(sorted_and_zipped[i][j])

    xvalues = range(0, len(lines[0]))
    plt.clf()
    maxy = 0
    maxx = max(xvalues)
    for i in range(len(lines)):
        maxy_this = max(lines[i])
        maxy = max(maxy_this, maxy)
        plt.plot(xvalues, lines[i], label=labels[i], linestyle=styles[i]) 

    plt.legend()
    plt.xlabel("CGRA Design No")
    plt.ylabel("Number of Loops that can Compile")
    plt.xlim([0, maxx])
    plt.ylim([0, maxy + 1])
    plt.savefig(tname + "_lines.png")
    plt.savefig(tname + "_lines.eps")

    print("Done!")
    if not plotting_rulesets:
        print(improvements)
        print("Geomean improvement is ", statistics.geometric_mean(improvements))

def plot_from_dicts(names, tname, dicts):
    xvalues = set()
    for d in dicts:
        for k in d.keys():
            xvalues.add(k)
    # TODO --- probably we should do beetter than the string
    # sort.
    xvalues = sorted(list(xvalues))
    # Keep track of bar width and position.
    xpos = np.arange(0.0, float(len(xvalues)))
    offset = 0.8 / float(len(dicts))
    plt.xlabel('CGRA Design')
    plt.ylabel('How Many Loops can Compile to this CGRA?')
    i = 0
    for d in dicts:
        lab = names[i]
        i += 1
        # Build y values for this set of results.
        yvalues = []
        for x in xvalues:
            if x in d:
                yvalues.append(d[x])
            else:
                # Presumably due to failure?  Perhaps should mark as so?
                yvalues.append(0)
        # Plot
        print("Plotting ", yvalues)
        plt.bar(xpos, yvalues, width=offset, label=lab)
        xpos += offset

    plt.legend()
    plt.savefig(tname)

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('target_graph_name')
    parser.add_argument('files', nargs='+')
    parser.add_argument('--rulesets', help='Draw the rulesets graph', action='store_true', default=False)

    args = parser.parse_args()
    results = []
    for f in args.files:
        results.append(load_from_file(f))

    if args.rulesets:
        plot_from_dicts(rulesets_labels, args.target_graph_name, results)
        plot_line_from_dicts(rulesets_labels, args.target_graph_name, results, args.rulesets)
    else:
        plot_from_dicts(rewriter_modes_labels, args.target_graph_name, results)
        plot_line_from_dicts(rewriter_modes_labels, args.target_graph_name, results, args.rulesets)
