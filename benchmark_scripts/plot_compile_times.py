import matplotlib.pyplot as plt
from matplotlib import cm
import numpy as np
import argparse

def load_from_file(fname):
    data = []
    with open(fname) as f:
        line = f.readlines()[0].split(',')
        for elem in line:
            # file ends in , so skip the empty one
            if elem.strip():
                if "%" in elem or "s" in elem or 'kernel' in elem or 'in' in elem:
                    # This is only a problem if there are loads of these, we have
                    #  a lto of data points
                    print ("Warning: read the wrong line when extracting compile times")
                    continue
                if ":" in elem:
                    mins=float(elem.split(":")[0].strip())
                    secs=float(elem.split(":")[1].strip())
                    time = mins * 60.0 + secs
                else:
                    time = float(elem.strip())
                data.append(time)

    return data

def get_cdf(data):
    yvalues = np.linspace(0.0, 1.0, len(data))
    xvalues = sorted(data)

    # Threshold anything bigger than the timout out -- it timed out, but the machine
    # often took a little while to shut the proceess down.
    timeout_spot = 0
    for xv in range(len(xvalues)):
        if xvalues[xv] > 300.0:
            timeout_spot = xv
            break
    return xvalues[:timeout_spot], yvalues[:timeout_spot]

# Compute the fail rates for the 50 nearest benchmarks.
def compute_fail_rates(succs, fails):
    # strength = len(fails) / len(succs) * 2.0 # Add factor of two to adjust for density of successes in the low parts of hte graph
    strength = 1.0
    print("Using strength ", strength)
    succs = [(x, strength) for x in succs]
    fails = [(x, 0.0) for x in fails]

    # sort by the x component
    vals = sorted(succs + fails)
    vals = [heat for (x, heat) in vals]
    #Compute a window around each point of size 0.1 in the cumlative distribution.
    window_size = len(vals) // 50
    values_stack = vals[0:window_size][::-1] # do reversed so we append and pop off front
    start = np.mean(values_stack)

    heats = [start] * window_size
    for value in vals[window_size:-window_size]:
        values_stack = values_stack[1:]
        values_stack.append(value)
        mean = np.mean(values_stack)
        heats.append(mean)

    # Now, put the last mean 50 times also
    last_mean = np.mean(values_stack)
    heats = heats + ([last_mean] * window_size)
    return heats

line_names = ["FlexC"]
def plot(successes, fails):
    i = 0
    plt.figure(figsize=(6, 3.0))
    xvalues, yvalues = get_cdf(successes + fails)
    # Compute the fail rates at every point in this CDF.
    fail_rates = compute_fail_rates(successes, fails)[:len(xvalues)] # Note that we cut off the x/yvals after the timeout, so we need to cut this also.
    scatter = plt.scatter(xvalues, yvalues, c=cm.cool(fail_rates), s=2.0, cmap=cm.cool, edgecolor='none', label=line_names[i])

    # plt.legend()
    plt.ylim([0.0, 1.0])
    plt.xlim([0, 300])
    plt.xlabel('Seconds')
    plt.ylabel('Cumlative Distribution Function')
    plt.text(10, 0.015, "} ", size=18)
    plt.text(25, 0.03, "Greedy Often Successful")
    plt.text(45, 0.16, "} ", size=25)
    plt.text(60, 0.19, "e-graphs Often Successful")
    plt.colorbar(cm.ScalarMappable(cmap=cm.cool), label='Compile Rate')
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

    plot(successful, failed)
