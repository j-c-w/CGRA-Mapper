import matplotlib.pyplot as plt
import numpy as np
import argparse

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

labels = ['OpenCGRA', 'Rewriter', 'EGraphCGRA']
styles = ['--', '-.', ':']
def plot_line_from_dicts(tname, dicts):
    zipped_lines = {}
    first_dsize = len(dicts[0])
    for d in dicts:
        dsize = len(d)
        assert dsize == first_dsize # If these are different, something failed e.g. with eggraphs that didn't fail without it 
        # They should both be equally excluded at a previous stage (since if egraphs fails we just won't use it and
        # can assume unchanged support --- really going to be due to bugs rather than fundamental issues though.)
        # TODO -- we could probably support that in this graph anyway?
        for k in d.keys():
            if k in zipped_lines:
                zipped_lines[k].append(d[k])
            else:
                zipped_lines[k] = [d[k]]

    # Now, sort that dict by magnitude of the first element, 
    # and unzip.
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
    plt.xlabel("CGRA Design Number")
    plt.ylabel("Number of Loops that can Compile")
    plt.xlim([0, maxx])
    plt.ylim([0, maxy])
    plt.savefig(tname + "_lines.png")
    plt.savefig(tname + "_lines.eps")

def plot_from_dicts(tname, dicts):
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
        lab = labels[i]
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

    args = parser.parse_args()
    results = []
    for f in args.files:
        results.append(load_from_file(f))

    plot_from_dicts(args.target_graph_name, results)
    plot_line_from_dicts(args.target_graph_name, results)
