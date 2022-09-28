import matplotlib.pyplot as plt
import argparse
import numpy as np
import statistics

colors=['#818fa6', '#6ea5ff', '#95c983', '#c99083', '#e079d6']
hatching=['O', 'o', '.', '-', 'x']
skip_bars=["All Rules"] # Just plot individual rulesets

# Note that this function is used by the plot_case_studies_rules.py
# script.
def load_data(f):
    lines = {}
    with open(f) as f:
        for line in f.readlines():
            line = line.split(',')
            # Get the number of successes
            succs = int(line[1])
            fails = int(line[2])
            total = int(line[3])
            lines[line[0]] = float(succs) / (float (total))
            # Should we track fails? (line[2])
    return lines

def plot(name, cca, maeri, revamp, sc_cgra):
    # Create a series for each entry.
    snames = sorted(cca.keys(), key=lambda x: sc_cgra[x])
    series = []
    names = []
    baselines = []
    increase = []
    for label in snames:
        if label in skip_bars:
            continue
        if label == 'Stochastic Rules':
            # Stochastic rules are only applicable to the SC-CGRA
            values = [
                    # Not clear if there is a better way to do this?
                    0.0, 0.0, 0.0,
                    sc_cgra[label]
                ]
        else:
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
    if len(increases) > 0:
        print("Geomean is: ", statistics.geometric_mean(increases))

    width = 0.75 / float(len(series))
    offset = -width * len(series) / 2.0
    print("Offset is ", offset, "xvals is ", len(series[0]))
    xvals = np.arange(len(series[0]))

    for i in range(len(series)):
        plt.bar(xvals + offset, series[i], width=width, label=names[i], color=colors[i], hatch=hatching[i])
        offset += width
    
    plt.gca().set_xticks(xvals)
    xlabels = ["CCA", "Maeri", "REVAMP", "SC-CGRA"]
    plt.gca().set_xticklabels(xlabels)
    plt.xlabel("Architecture")
    plt.ylabel("Fraction of Loops Compiled to Accelerator")
    if name == 'case_studies':
        plt.text(2.7, 0.68, 'Stochastic\n  Ruleset')
        plt.legend()
        plt.ylim(0.0, 0.735)
    else:
        plt.legend(ncol=3, loc=(0, 1.08))
    plt.tight_layout()

    plt.savefig(name + ".png")
    plt.savefig(name + ".eps")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('name') # which file name for output (case_studies or ruleset_studies)
    parser.add_argument("cca")
    parser.add_argument("maeri")
    parser.add_argument("revamp")
    parser.add_argument("sc_cgra")
    args = parser.parse_args()

    cca = load_data(args.cca)
    maeri = load_data(args.maeri)
    revamp = load_data(args.revamp)
    sc_cgra = load_data(args.sc_cgra)

    plot(args.name, cca, maeri, revamp, sc_cgra)
