These benchmarks are from:

https://github.com/tancheng/CGRA-Bench

And also from the LivermoreC Loops

Some of the benchmarks are omitted because they are too big for OpenCGRA to map to heterogeneous CGRAs.  These are:

	- adpcm_coder/
	- adpcm_decoder/

We also omit:
	- susan
As we were unable to get this benchmark to run.

For benchmarks with multiple key loops, we benchmark each loop independently.  Folders are named <Name>N


##Instructions

To gather the II data, run ./run_all_in_context_benchmarks.sh benchmark_data

###A5 Data Gathering Instructions
Get the A5 repo (link TODO).

Go into utils.h, and set:
`#define IN_CONTEXT`.

Then:
1. Set `#define RUN_UNINSTRUMENTED`.  Take the output and put it in A5_output/BenchmarkTimes
2. Set `#define TIME_LOOPS`.  Take the output and put it in A5_output/LoopTimes
3. Set `#define COUNT_ITERS`. Take the output and put it in A5_output/LoopIters
