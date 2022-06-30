#!/usr/bin/env python3
import matplotlib.pyplot as plt
import argparse
import os
import numpy as np
import statistics

def load_estimated_performances(folder):
    performance_dict = {} #Lookup is from loop number to the estimated number of cycles.
    for file in os.listdir(folder):
        if file.endswith('.c.iters'):
            # Get the number of that file, which should be of the form:
            # loopX.c.iters
            number = int(file[4:-8])
            with open(folder + '/' + file) as f:
                line = ''.join(f.readlines()).strip()
                if line:
                    has_data = True
                    data = float(line)
                else:
                    has_data = False
            if has_data:
                performance_dict[number] = data
    return performance_dict

def load_cgra_performances(cgra_folder):
    iis = {}
    for file in os.listdir(cgra_folder):
        # Note that we can also get the accelerator number from the
        # filename here, but don't currenlty use that.
        with open(cgra_folder + '/' + file) as f:
            for line in f.readlines():
                name, ii = line.split(',')
                print (line)
                # Get the loop number we are compiling for
                # It's of the form kernel_X.bc
                number = int(name[11:-3])
                print("Loading number", number, line)
                if number in iis:
                    iis[number].append(int(ii))
                else:
                    iis[number] = []
    return iis

# We need to have both the CPU and the CGRA on the same page.
# This converts the CPU model to time.
# From doc here: https://riscv.org/wp-content/uploads/2018/07/DAC-SiFive-Drew-Barbier.pdf
def compute_processor_time(proc_cycles):
    freq = 50.0 # Mhz --- 50mhz in low power mode, 210 in hp mode.
    time = proc_cycles / (freq * 1000_000.0)
    return time

# This converts the CGRA model to time.
# Using the paramters from Snafu
def compute_cgra_time(cgra_cycles):
    freq = 50.0 # Mhz
    time = cgra_cycles / (freq * 1000_000.0)
    return time

def plot_speedups(cpu_cycles, cgra_cycles):
    speedups = []
    print(cgra_cycles)
    for loop in cgra_cycles:
        # If this doesn't exist, mca failed where llvm succeedd --- hopefully
        # not happening? failing loops can be skipped if this does
        # happen.
        cpu_time = compute_processor_time(cpu_cycles[loop])
        for cycles in cgra_cycles[loop]:
            cgra_time = compute_cgra_time(cycles)

            speedups.append(cpu_time / cgra_time)

    # Now we have the speedups, plot a CDF.
    stepsize = 1.0 / len(speedups)
    xvals = sorted(speedups)
    step = 1.0 / float(len(speedups))
    yvals = np.linspace(0.0, 1.0, len(speedups))
    print("Got ", len(xvals), "xvals", len(yvals), "yvals")

    # duplicate the last element to make the graph go
    # all the way to the top and look cleaner.
    plt.plot(xvals, yvals, label='Loop Execution Time')
    plt.ylabel("Cumlative Distribution Function")
    plt.xlabel('Speedup')
    plt.ylim([0.0, 1.0])
    plt.savefig('speedups.png')
    plt.savefig('speedups.eps')
    print ("Done!")
    print ("Geomean improvement is ", statistics.geometric_mean(speedups))


if __name__ == "__main__":
    parser = argparse.ArgumentParser('plot the performance graph')
    parser.add_argument('CPUFolder')
    parser.add_argument('CGRAFolder')

    args = parser.parse_args()

    estimated_performances = load_estimated_performances(args.CPUFolder)
    cgra_performances = load_cgra_performances(args.CGRAFolder)

    plot_speedups(estimated_performances, cgra_performances)
