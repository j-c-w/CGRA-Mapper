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
./compile.sh kernel.cpp
./run.sh kernel.bc --build
./build_param.sh operations.json param.json

shift
touch run_output

## Now run over all other input files.
typeset -a files
for file in $(find $1 -name "loop*.c"); do
	files+=($file)
done

if [[ ${#use_egraphs} == 0 ]]; then
	parallel -v '(
		cp {} kernel_{#}.cpp
		./compile.sh kernel_{#}.cpp
		./run.sh kernel_{#}.bc --params-file param.json
		echo "Building {} "
			)' ::: ${files[@]} &> run_output
else
	parallel '(
		cp {} kernel_{#}.cpp
		./compile.sh kernel_{#}.cpp
		./run.sh kernel_{#}.bc --params-file param.json --use-egraphs
		echo "Building {}")' ::: ${files[@]} &> run_output
fi

success=$(grep -ce "Mapping:success" run_output || echo "")
fails=$(grep -ce "Mapping:fail" run_output || echo "")

mv run_output run_output.old

echo "Have $success successes, $fails fails"
