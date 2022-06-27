import matplotlib.pyplot as plt
import numpy as np
import argparse

def load_from_file(fname):
    data = []
    with open(fname) as f:
        line = f.readlines()[0].split(',')
        for elem in line:
            # file ends in , so skip the empty one
            if elem.strip():
                data.append(float(elem.strip()))

    return data

def get_cdf(data):
    yvalues = np.linspace(0.0, 1.0, len(data))
    xvalues = sorted(data)
    return xvalues, yvalues

line_names = ["Time: Success", "Time: Fail"]
def plot(lines):
    i = 0
    plt.figure(figsize=(6, 3.0))
    for line in lines:
        xvalues, yvalues = get_cdf(line)
        plt.plot(xvalues, yvalues, label=line_names[i])

        i += 1

    plt.legend()
    plt.ylim([0.0, 1.0])
    plt.xlim([0, 70])
    plt.xlabel('Seconds')
    plt.ylabel('Cumlative Distribution Function')
    plt.tight_layout()
    plt.savefig('compile_times.png')
    plt.savefig('compile_times.eps')

if __name__ == "__main__":
    parser = argparse.ArgumentParser("Plot the compile time graph --- input files should be CSV of the compile times")
    parser.add_argument('successful_compiles')
    parser.add_argument('failed_compiles')
    args = parser.parse_args()

    successful = load_from_file(args.successful_compiles)
    failed = load_from_file(args.failed_compiles)

    plot([successful, failed])