import matplotlib.pyplot as plt
import numpy as np
import argparse
import re

def process_file(file_path):
    times = []
    with open(file_path, 'r') as file:
        for line in file:
            match = re.search(r'in (\d+\.\d+)ms:', line)
            if match:
                time_in_ms = float(match.group(1))
                times.append(time_in_ms)
    return times

def name_map(inp_name):
    if 'sc_cgra' in inp_name:
        return 'SC-CGRA'
    if 'maeri' in inp_name:
        return 'Maeri'
    if 'cca' in inp_name:
        return 'CCA'
    if 'revamp' in inp_name:
        return 'REVAMP'

    return inp_name

colors=['#818fa6', '#6ea5ff', '#95c983', '#c99083', '#e079d6']

def color_map(inp_name):
    if 'sc_cgra' in inp_name:
        return colors[3]
    if 'maeri' in inp_name:
        return colors[1]
    if 'cca' in inp_name:
        return colors[0]
    if 'revamp' in inp_name:
        return colors[2]

def plot_cdf(times, name, color):
    # Sort the times
    sorted_times = np.sort(times)

    # Calculate the CDF values
    cdf = np.arange(1, len(sorted_times) + 1) / len(sorted_times)

    # Plot the CDF
    plt.plot(sorted_times, cdf, linestyle='-', marker=None, label=name, color=color)
    plt.xlabel('Time (ms)')
    plt.ylabel('CDF')
    plt.xscale('log')
    plt.grid(True)


def main():
    # Create the argument parser
    parser = argparse.ArgumentParser(description="Plot CDFs")

    # Add an argument for multiple file paths
    parser.add_argument('files', nargs='+', help='time files')

    # Parse the arguments
    args = parser.parse_args()

    plt.figure(figsize=(5, 2.5))

    # Print the file paths
    for file in args.files:
        times = process_file(file)
        name = name_map(file)
        color = color_map(file)

        plot_cdf(times, name, color)

    plt.legend()
    plt.tight_layout()
    plt.savefig('compile_times_new.eps')
         

if __name__ == "__main__":
    main() 
