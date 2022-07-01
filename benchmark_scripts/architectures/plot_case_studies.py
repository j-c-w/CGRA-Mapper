import matplotlib.pyplot as plt
import argparse
import numpy as np
import statistics

def load_data(f):
    lines = {}
    with open(f) as f:
        for line in f.readlines():
            line = line.split(',')
            # Get the number of successes
            succs = int(line[1])
            fails = int(line[2])
            lines[line[0]] = float(succs) / (float (succs + fails))
            # Should we track fails? (line[2])
    return lines

def plot(cca, maeri, revamp, sc_cgra):
    # Create a series for each entry.
    snames = sorted(cca.keys(), key=lambda x: cca[x])
    series = []
    names = []
    for label in snames:
        values = [
            cca[label],
            maeri[label],
            revamp[label],
            sc_cgra[label]
        ]
        series.append(values)
        names.append(label)
        if label == 'OpenCGRA':
            baselines = values
        elif label == 'FlexC':
            increase = values

    increases = []
    for i in range(len(baselines)):
        increases.append(increase[i]/ baselines[i])

    print("Increases were: ", increases)
    print("Geomean is: ", statistics.geometric_mean(increases))

    width = 0.75 / float(len(series[0]))
    offset = -width * 2.0
    print("Offset is ", offset, "xvals is ", len(series[0]))
    xvals = np.arange(len(series[0]))

    for i in range(len(series)):
        plt.bar(xvals + offset, series[i], width=width, label=names[i])
        offset += width
    
    plt.gca().set_xticks(xvals)
    xlabels = ["CCA", "Maeri", "REVAMP", "SC-CGRA"]
    plt.gca().set_xticklabels(xlabels)
    plt.xlabel("Architecture")
    plt.ylabel("Fraction of Loops Successfully Compiled")
    plt.legend()

    plt.savefig("case_studies.png")
    plt.savefig("case_studies.eps")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("cca")
    parser.add_argument("maeri")
    parser.add_argument("revamp")
    parser.add_argument("sc_cgra")
    args = parser.parse_args()

    cca = load_data(args.cca)
    maeri = load_data(args.maeri)
    revamp = load_data(args.revamp)
    sc_cgra = load_data(args.sc_cgra)

    plot(cca, maeri, revamp, sc_cgra)
