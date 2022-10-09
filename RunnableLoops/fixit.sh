#!/bin/bash

set -u

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 <file to fix>"
	exit 1
fi

runnable=$1

gcc -g -w $runnable -fsanitize=address utils.c -O0
./a.out &> tempout
retcode=$?
n=0

touch deleted_loops

while (( $retcode != 0 )); do
	runfun=$(grep tempout -m 1 -oe 'run_f[0-9]*')
	n=$((n + 1))
	echo "Deleting $runfun --- $n deleted so far."
	echo $runfun >> deleted_loops

	set -x
	sed "s/^$runfun();//" -i $runnable

	gcc -g -w $runnable -fsanitize=address utils.c -O0
	./a.out &> tempout
	retcode=$?
done


echo "Done"
