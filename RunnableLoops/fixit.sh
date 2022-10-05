#!/bin/bash

set -u

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 <file to fix>"
	exit 1
fi

runnable=$1

gcc -g -w $runnable -fsanitize=address
./a.out &> tempout
retcode=$?
n=0

while (( $retcode != 0 )); do
	runfun=$(grep tempout -m 1 -oe 'run_f[0-9]*')
	n=$((n + 1))
	echo "Deleting $runfun --- $n deleted so far."

	set -x
	sed "s/^$runfun();//" -i $runnable

	gcc -g -w $runnable -fsanitize=address
	./a.out &> tempout
	retcode=$?
done

echo "Done"
