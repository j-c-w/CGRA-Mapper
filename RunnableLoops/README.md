###Instructions for Comparing Loops.

Get the runnable loops database.

#Getting the runnable loops:
1. Run ./extract_runnable_loops.py <loops_db> output
2. Run ./fixit.sh output/runnable.c

#Executing the runnable loops:
1. Open the CCES.
2. Paste output/runnable.c into Core/SRC/loops_data.c, and change 'int main()' into 'int loops_execute()'
3. Go into utils.h for an instrumented run, set:
	3.1. LOOP_ITERATION loop_iteration()
	3.2. START(u) loop_start(u)
	3.3. END(u) loop_end(u)
	3.4. Copy and paste the output from the debugger into data/A5.iterations
4. Run the code --- while it is failing, delete the failing functions (if you are using the pre-computed version , you can skip this rather time-consuming step, as I have already done this over the course of a couple of days)
5. Go into tuils.h for an uninstrumented run, set:
	3.1. LOOP_ITERATION /* (to empty) */
	3.2. START(u) loop_start(u)
	3.3. END(u) loop_end(u)
	3.4. Copy and paste the output from the debugger into data/A5.times

#CGRA Execution Baselines
These can be computed using the:

./benchmark_cgras.sh 0.5 output/loops temp_folder

0.5 can be reduced to a smaller number (0 to 1) to save compilation time.
For slurm users, you can use:

./benchmark_cgras_slurm.sh output/loops 500 0.5

(500 and 0.5 can be reduced to save computation time --- note that this will submit 500 jobs).


command
