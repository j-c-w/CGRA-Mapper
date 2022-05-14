#!/bin/zsh

set -eu

typeset use_egraphs
zparseopts -D -E -use-egraphs=use_egraphs

if [[ $# -ne 2 ]]; then
	echo "Usage: $0 <CGRA Design File> <Other Input Files Base Folder>"
	echo "--use-egraphs to use egraph rewriting"
	echo "Other files should all be in the format loopX.c (X a number)"
	exit 1
fi

## Build the CGRA.
cp $1 kernel.cpp
echo "Building kernel "
cat kernel.cpp

## Build the initial CGRA.
./compile.sh
./run.sh --build
./build_param.sh operations.json

shift
touch run_output

## Now run over all other input files.
for file in $(find $1 -name "loop*.c"); do
	echo "Building $file"
	echo "Building $file " >> run_output
	cp $file kernel.cpp
	./compile.sh
	if [[ ${#use_egraphs} == 0 ]]; then
		./run.sh &>> run_output
	else
		./run.sh --use-egraphs &>> run_output
	fi
done

success=$(grep -ce "Mapping:success" run_output || echo "")
fails=$(grep -ce "Mapping:fail" run_output || echo "")

mv run_output run_output.old

echo "Have $success successes, $fails fails"
