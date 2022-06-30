import matplotlib.pyplot as plt
import argparse
import numpy as np

def load_data(f):
    lines = {}
    with open(f) as f:
        for line in f.readlines():
            line = line.split(',')
            # Get the number of successes
            lines[line[0]] = int(line[1])
            # Should we track fails? (line[2])
    return lines

def plot(cca, maeri, revamp, sc_cgra):
    # Create a series for each entry.
    snames = cca.keys()
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
    plt.ylabel("Compiles")
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
