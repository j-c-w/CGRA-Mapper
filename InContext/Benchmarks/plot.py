import argparse
import re
import matplotlib.pyplot as plt
import numpy as np

# skip these as all architectures fail on them so they just clutter the already cluttered grpah.
skip = ['fft', 'conv', 'mvt', 'relu']

colors=['#818fa6', '#6ea5ff', '#95c983', '#c99083', '#e079d6'] 
hatching=['O', 'o', '.', '..', '-', 'x']

# note terminology -- bench = livermorec
# loop = livermorec3 (e.g.)

architectures = ['cca.json', 'maeri.json', 'revamp.json', 'sc-cgra.json']
modes = ['opencgra', 'llvm', 'greedy', 'flexc']

arch_lookup = {
        'cca.json': 'CCA',
        'maeri.json': 'Maeri',
        'revamp.json': 'REVAMP',
        'sc-cgra.json': 'SC-CGRA'
        }
mode_lookup = {
        'opencgra': 'OpenCGRA',
        'greedy': 'Greedy',
        'flexc': 'FlexC',
        'llvm': 'LLVM'
        }

def benchmark_for_loop(loop):
    return re.sub('[0-9]*', '', loop)

def sum_dicts(x, y):
    res = {}
    for k in x:
        res[k] = x[k] + y[k]
    return res

def ratio_dicts(x, y):
    res = {}
    for k in x:
        res[k] = x[k] / y[k]
    return res

# returns loop -> time
def remove_unreplaceable_loops(acc_times, default_times):
    new_acc_times = {}
    for loop in acc_times:
        # We use -1 to indicate failuers --- after the vaiours
        # multiplcaitons, we check if -ve
        if acc_times[loop] <= 0:
            new_acc_times[loop] = default_times[loop]
        else:
            new_acc_times[loop] = acc_times[loop]

    return new_acc_times

# returns benchmark->time
def compute_unaccelerated_times(benchmark_times, loop_times):
    result = {}
    # copy to avoid in-place modification.
    for benchmark in benchmark_times:
        result[benchmark] = benchmark_times[benchmark]

    for loop in loop_times:
        benchmark = benchmark_for_loop(loop)

        result[benchmark] -= loop_times[loop]

    return result

# returns benchmark -> time (takes loop -> time)
def sum_replacement_times(loop_times):
    result = {}

    for loop in loop_times:
        benchmark = benchmark_for_loop(loop)
        if benchmark in result:
            result[benchmark] += loop_times[loop]
        else:
            result[benchmark] = loop_times[loop]
    return result

mhz = 100000000.0 # hz of accelerator

#returns loop -> time
def compute_replacement_times(iis, iters):
    global mhz

    result = {}

    for loop in iis:
        ii = iis[loop]
        iter_count = iters[loop]

        # iters 
        result[loop] = float(ii * iter_count)
        # seconds
        result[loop] = result[loop] / mhz

    return result

# map from loop -> number of tiers (all executions)
def load_loop_iterations(folder):
    result = {}

    with open(folder + '/LoopIters', 'r') as f:
        lines = f.readlines()

        for line in lines:
            if line.startswith('Starting') or line.startswith('Benchmark') or line.startswith('Finished'):
                continue
            bmark, iters, _ = line.split(',')
            bmark = bmark
            iters = int(iters)
            if bmark in result:
                result[bmark] += iters
            else:
                result[bmark] = iters
    return result

# map from loop -> total time in that loop (all executions)
def load_loop_times(folder):
    result = {}

    with open(folder + '/LoopTimes', 'r') as f:
        lines = f.readlines()
        for line in lines:
            if line.startswith('Starting') or line.startswith('Benchmark') or line.startswith('Finished'):
                continue
            bmark, _, time = line.split(',')
            bmark = bmark
            time = float(time)

            if bmark in skip:
                continue

            if bmark in result:
                result[bmark] += time
            else:
                result[bmark] = time
    return result

# map from bench -> time
def load_execution_times(folder):
    result = {}

    with open(folder + '/BenchmarkTimes', 'r') as f:
        lines = f.readlines()

        for line in lines:
            if line.startswith("Finished "):
                bmark = line.split(" ")[1][:-1]
                time = float(line.split(" ")[2])

                if bmark in skip:
                    continue

                result[bmark] = time
    return result

def load_data(lines):
    res = {}
    for line in lines:
        mode, ii = line.strip().split(',')
        if ii == "Failed":
            ii = -1
        else:
            ii = int(ii.split(' ')[1])
        res[mode] = ii
    return res

# return a double dict --- from arch -> mode -> loop -> II (-1 for fialed)
def load_iis(folder, loops):
    global skip
    iis = {}
    for arch in architectures:
        loop_iis = {}
        for mode in modes:
            loop_iis[mode] = {}

        for loop in loops:
            if loop in skip:
                continue
            this_folder = folder + '/' + arch + '_' + loop
            with open(this_folder + '/data', 'r') as f:
                # bit more complicated loop bc we need to inver the data here.
                data = load_data(f.readlines())
                for mode in data:
                    loop_iis[mode][loop] = data[mode]

        iis[arch] = loop_iis

    return iis

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument('ii_folder')
    parser.add_argument('a5_folder')

    args = parser.parse_args()

    loops = []
    with open('Working') as f:
        for line in f.readlines():
            bench = line.strip()
            # Skip benchmarks that don't work on any archtiectures
            # (most common reason is / op)
            if bench in skip:
                continue
            loops.append(bench)

    benchmarks = set()
    for loop in loops:
        benchmark = benchmark_for_loop(loop)
        benchmarks.add(benchmark)

    speedups = {} # Arch -> benchmark -> speedup

    # Load the IIs.
    iis_by_arch = load_iis(args.ii_folder, loops) # arch -> mode -> loop -> II
    for mode in modes:
        for arch in architectures:
            # apparenlty this is swapping this again?
            if arch not in speedups:
                speedups[arch] = {}
            iis = iis_by_arch[arch][mode] # loop -> II

            # Load benchmark execution times.
            execution_times = load_execution_times(args.a5_folder) # benchmark -> time

            # Load time spent in each loop.
            loop_times = load_loop_times(args.a5_folder) # loop -> time

            # Load iterations in each loop.
            iterations = load_loop_iterations(args.a5_folder) # loop -> iteration

            # Compute the replacement times for each loop using the II
            replacement_times = compute_replacement_times(iis, iterations) # loop -> time (using accelerator)
            corrected_replacement_times = remove_unreplaceable_loops(replacement_times, loop_times) # loop -> time (using accelerator only where supported and cpu time otherwise)
            total_replacement_times = sum_replacement_times(corrected_replacement_times) # benchmark -> time (using acceleraotr)

            # Compute the benchmark time left /outside/ of the loops (per benchmark not per loop).
            base_unaccelerated_times = compute_unaccelerated_times(execution_times, loop_times)# benchmark -> time

            # Compute the speedups.
            this_new_times = sum_dicts(base_unaccelerated_times, total_replacement_times) # benchmark -> time
            this_speedups = ratio_dicts(execution_times, this_new_times) # benchmark -> ratio
            speedups[arch][mode] = this_speedups # benchmark -> ratio

            print("mode is ", mode, "arch is", arch)
            print("original times was", execution_times)
            print("Base unaccelerated times is", base_unaccelerated_times)
            print("total replacement times is", total_replacement_times)
            print("Speedups is", this_speedups)

    # Now, do plotting.
    # speedups is arch -> mode -> benchmark -> time
    for mode in modes:
        plt.clf()
        for i in range(len(architectures)):
            arch = architectures[i]
            width = 1.0 / (len(architectures) + 1)
            offset = (i - len(architectures) / 2.0) * width

            formatted_arch = arch_lookup[arch]
            data = speedups[arch][mode]

            x = np.array(range(len(benchmarks)))
            y = [data[b] for b in sorted(benchmarks)]

            plt.bar(x + offset, y, label=formatted_arch, width=width, color=colors[i], hatch=hatching[i])
        plt.xticks(range(len(benchmarks)))
        plt.gca().set_xticklabels(sorted(benchmarks), rotation=90)
        plt.title(mode_lookup[mode])
        plt.ylim([0.0, 5.0])
        plt.ylabel("Speedup")
        plt.tight_layout()

        plt.legend()
        plt.savefig(mode + '_in_context_speedups.png')
        plt.savefig(mode + '_in_context_speedups.eps')
