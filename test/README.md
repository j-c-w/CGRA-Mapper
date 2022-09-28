These are the commands that get issued to run the benchmarks.

For the case studies, see ../benchmark_scripts/  

For the cross-comparisons and compile times, run:

./run_all_benchmarks_slurm.sh ../Loops4 500 0.2

(Note that 0.2 and 500 are sampling parameters to reduce the amount of computation required: 500 is how many architectures to test, and 0.2 is the fraction of loops to test against each architecture.)


Plotting:

python plot_successes.py successes.png run_all_benchmarks_outputs/no_rules_data run_all_benchmarks_outputs/llvm_data run_all_benchmarks_outputs/greedy_data run_all_benchmarks_outputs/rewriter_data
