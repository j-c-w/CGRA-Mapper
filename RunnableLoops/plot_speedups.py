import argparse
from re import I
import matplotlib.pyplot as plt
import numpy as np
import statistics

class Data:
    def __init__(self, iters, time):
        self.iters = iters
        self.time = time

# The A5 we are benchmarking against runs at 500MHz.
A5_MHZ = 500000000

def compute_cycles_per_iter(iterations, time):
    time_per_iter = time / iterations
    cycles_per_iter = time_per_iter * A5_MHZ
    return cycles_per_iter

def load_IIs(ii_file):
    iis = []
    with open(ii_file) as f:
        for line in f.readlines():
            num, ii = line.split(',')
            iis.append((int(num.strip()), int(ii.strip())))
    return iis

# This is a dict from ID->CPU time.
def load_cpu_data(data_file):
    data = {}
    with open(data_file) as f:
        lines = 0
        for line in f.readlines():
            if line.startswith('Starting'):
                continue
            lines += 1
            num, iters, time = line.split(', ')
            num = int(num.strip())
            iters = float(int(iters.strip()))
            time = float(time.strip())
            # print("Line is ", line)
            # print("Iters is", iters)

            #  for some of thesse, we cdon't get teh inputs
            # rigth to cause iterstioans.
            data[num] = Data(iters, time)
        print("Had ", lines, "lines in the file", "have", len(data), 'entries fro mthat file')
    return data

def plot(speedups):
    xvs = np.linspace(0.0, 1.0, len(speedups))
    plt.plot(xvs, speedups)
    plt.ylabel('Speedup')
    plt.xlabel('Loop/Architecture Combination (ordered by speedup)')
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, speedups[-1]])
    gmean = statistics.geometric_mean(speedups)

    plt.gca().axhline(gmean, color='green', linestyle='--')
    plt.text(0.5, gmean + 0.2, 'Geomean ({gmean:.2f})'.format(gmean=gmean), color='green')
    plt.gca().axhline(1.0, color='black', linestyle='--')
    plt.text(0.5, 1.0 + 0.6, 'Speedup Threshold', color='black')
    print ("Geomean improvement is ", gmean)
    plt.xticks(None)

    plt.savefig('speedups.eps')
    plt.savefig('speedups.png')

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('cpu_run_file', help='format is <number>, iterations, time =-- expect iterations to be 0')
    parser.add_argument('cpu_iters_file', help='iters file for CPU.  Format is <number>, iterations, time ')
    parser.add_argument('II_file', help='format is <number>, II')

    args = parser.parse_args()

    IIs = load_IIs(args.II_file)
    a5_times = load_cpu_data(args.cpu_run_file)
    a5_iters = load_cpu_data(args.cpu_iters_file)

    # Assume CGRA running at same freq as processor.
    speedups = []
    # print("at_times nums is ", a5_times.keys())
    for (num, II) in IIs:
        # Some of the parameter initializations do not
        # result in those loops being run -- filter those
        # out from any comparison.
        if num in a5_times and a5_iters[num].iters > 10:
            base_time = a5_times[num].time - 0.0000012 # Remove the overhead of timing. (time taken by 0 iteration loops)
            base_iters = a5_iters[num]

            base_cycles_per_iter = compute_cycles_per_iter(base_iters.iters, base_time)
            # smaller -> faster, so speedup >1 if II < base_cycles_per_iter.
            speedups.append(base_cycles_per_iter / II)
        else:
            print("Num", num, "did not get benchmarked on CPU.")
            pass

    # sort speeds and then plot as a line.
    speedups = sorted(speedups)

    plot(speedups)
