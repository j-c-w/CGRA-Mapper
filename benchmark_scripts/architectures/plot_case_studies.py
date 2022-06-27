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

def plot(cca, maeri, revamp):
    # Create a series for each entry.
    xlabels = cca.keys()
    series = []
    names = []
    for label in xlabels:
        values = [
            cca[label],
            maeri[label],
            revamp[label]
        ]
        series.append(values)
        names.append(label)

    width = 0.75 / float(len(series))
    offset = -width * (float(len(series)) / 2.0)
    xvals = range(len(series[0]))

    for i in range(len(series)):
        plt.bar(xvals + offset, series[i], width=width)
    
    plt.gca().set_xticklabels(xlabels)
    plt.xlabel("Architecture")
    plt.label("Compiles")
    plt.legend()

    plt.savefig("case_studies.png")
    plt.savefig("case_studies.eps")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("cca")
    parser.add_argument("maeri")
    parser.add_argument("revamp")
    args = parser.parse_args()

    cca = load_data(args.cca)
    maeri = load_data(args.maeri)
    revamp = load_data(args.revamp)

    plot(cca, maeri, revamp)