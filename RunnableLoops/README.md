###Instructions for Comparing Loops.

Get the runnable loops database.

#Getting the runnable loops:
1. Run ./extract_runnable_loops.py <loops_db> output
2. Run ./fixit.sh output/runnable.c

#Executing the runnable loops:
1. Open the STM32CubeIDE.
2. Paste output/runnable.c into Core/SRC/loops_data.c, and change 'int main()' into 'int loops_execute()'
3. Go into utils.h for an instrumented run, set:
	3.1. LOOP_ITERATION loop_iteration()
	3.2. START(u) loop_start(u)
	3.3. END(u) loop_end(u)
	3.4. Copy and paste the output from the debugger into data/InstrumentedM4
4. Go into tuils.h for an uninstrumented run, set:
	3.1. LOOP_ITERATION /* (to empty) */
	3.2. START(u) loop_start(u)
	3.3. END(u) loop_end(u)
	3.4. Copy and paste the output from the debugger into data/UninstrumentedM4

#Splitting loosp in half
Note that the STM32F411 board is too small to fit all the loops as one program.
You'll need to insert various #defines to split the runs up into multiple different runs, so
that they fit in the flash/RAM on the board.

#CGRA Execution Baselines
These can be computed using the:

./cgra_baselines.sh output/loops


command
