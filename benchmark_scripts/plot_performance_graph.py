#!/usr/bin/env python3
import traceback
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
            number = int(file.split('_')[2].split('.')[0])
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
            try:
                pairs = []
                for line in f.readlines():
                    name, ii = line.split(',')
                    # Get the loop number we are compiling for
                    number = int(name.split('_')[3].split('.')[0])
                    pairs.append((number, ii))
                for (number, ii) in pairs:
                    if number in iis:
                        iis[number].append(int(ii))
                    else:
                        iis[number] = []
            except:
                # The script that gets this stuff out is a bit fragile --- if
                # one entry in the file is broken, it's likely that they all are,
                # so skip the entire file.
                # There should be plenty of data points, so this shouldn't make
                # any difference to the graph provided  it doens't happen much.
                print("Warning: error laoding file " + file)
                print("Error was ")
                traceback.print_exc()
    return iis

# We need to have both the CPU and the CGRA on the same page.
# This converts the CPU model to time.
# From doc here: https://riscv.org/wp-content/uploads/2018/07/DAC-SiFive-Drew-Barbier.pdf
def compute_processor_time(proc_cycles):
    freq = 210.0 # Mhz --- 50mhz in low power mode, 210 in hp mode.
    time = proc_cycles / (freq * 1000_000.0)
    return time

# This converts the CGRA model to time.
# Using the paramters from ADRES reported by REVAMP
def compute_cgra_time(cgra_cycles):
    freq = 100.0 # Mhz
    time = cgra_cycles / (freq * 1000_000.0)
    return time

def plot_speedups(cpu_cycles, cgra_cycles):
    speedups = []
    print(cgra_cycles)
    print(cpu_cycles)
    for loop in cgra_cycles:
        # If this doesn't exist, mca failed where llvm succeedd
        # Failed loops are just skipped -- the reasons I have seen for failure
        # are to do with target-specific information for the RISC-V target,
        # such as typedefs that are incompatible with the defined
        # types on the risc-v target.
        # (Failures along these lines are super rare)
        if loop in cpu_cycles:
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
    plt.plot(yvals, xvals, label='Loop Execution Time')
    plt.ylabel("Cumlative Distribution Function")
    plt.ylabel('Speedup')
    plt.xlabel('Loop/Architecture Combination (ordered by speedup)')
    plt.xlim([0.0, 1.0])
    # plt.xlim([0.0, 20.0])
    plt.gca().axhline(1.0, color='black', linestyle='--')
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
