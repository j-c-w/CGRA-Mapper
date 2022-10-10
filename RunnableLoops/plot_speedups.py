import argparse
import matplotlib.pyplot as plt
import numpy as np
import statistics

# The A5 we are benchmarking against runs at 500MHz.
A5_MHZ = 500000000

def load_IIs(ii_file):
    iis = []
    with open(ii_file) as f:
        for line in ii_file.readlines():
            num, ii = line.split(',')
            iis.append((num, int(ii.strip())))
    return iis

# This is a dict from ID->CPU time.
def load_cpu_data(data_file):
    data = {}
    with open(data_file) as f:
        for line in data_file.readlines():
            if line.startswith('Starting'):
                continue
            num, iters, time = line.split(', ')
            iters = float(int(iters.strip()))
            time = float(time.strip())

            # 
            time_per_iter = time / iters
            cycles_per_iter = time_per_iter * A5_MHZ
            data[num] = cycles_per_iter

def plot(speedups):
    xvs = range(0, len(speedups))
    plt.plot(xvs, speedups)
    plt.set_ylabel('Speedup')
    plt.set_xlabel('Benchmark')
    plt.set_xticks(None)

    plt.savefig('speedups.eps')
    plt.savefig('speedups.png')

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('cpu_run_file', help='format is <number>, iterations, time')
    parser.add_argument('II_file', help='format is <number>, II')

    args = parser.parse_args()

    IIs = load_IIs(args.II_file)
    a5_runs = load_cpu_data(parser.cpu_run_file)

    # Assume CGRA running at same freq as processor.
    speedups = []
    for (num, II) in IIs:
        base_num = a5_runs[num]
        speedups.append(base_num / IIs)

    # sort speeds and then plot as a line.
    speedups = sorted(speedups)

    plot(speedups)
