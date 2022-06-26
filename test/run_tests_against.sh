#!/bin/zsh

set -eu

typeset use_egraphs use_rewriter
zparseopts -D -E -use-egraphs=use_egraphs -use-rewriter=use_rewriter

if [[ $# -ne 4 ]]; then
	echo "Usage: $0 <Reduction Rate> <CGRA Design File> <Other Input Files Base Folder> <Temp Folder>"
	echo "--use-egraphs to use egraph rewriting"
	echo "--use-rewriter to use greedy rewriting"
	echo "Other files should all be in the format loopX.c (X a number)"
	echo "Reduction rate is the fraction of files to benchmark agains.  Files will be sorted with the gnu sort, then the first <reduction rate> fraction will be used."
	exit 1
fi

temp_folder=$4
rm -rf $temp_folder
mkdir -p $temp_folder
# The location of this should be set to the built libmapper pass.
lmapper=../build/src/libmapperPass.so

## Build the CGRA.
cp $2 $temp_folder/kernel.cpp
echo "Building kernel "
cat $temp_folder/kernel.cpp
reduction_rate=$1

## Build the initial CGRA.
original_folder=$PWD
pushd $temp_folder
cp $original_folder/param_example.json param.json #use the param example to build the actual params.
$original_folder/compile.sh kernel.cpp
$original_folder/run.sh $original_folder/$lmapper kernel.bc --build
$original_folder/build_param.sh $original_folder/param_skeleton operations.json param.json

touch run_output

## Now run over all other input files.
typeset -a files
echo "Looking for files in $original_folder/$3"
for file in $(find $original_folder/$3 -name "loop*.c" -print0 | sort -z); do
	files+=($file)
done
echo "Before reducing, have ${#files[@]}"
number_to_have=$(( $reduction_rate * ${#files[@]} ))
number_to_have=$((${number_to_have%.*}))
files=( "${files[@]:1:$number_to_have}" )
echo "Running over files ${files[@]}"

extra_flags=""
if [[ ${#use_egraphs} -gt 0 ]]; then
	extra_flags="$extra_flags --use-egraphs"
fi
if [[ ${#use_rewriter} -gt 0 ]]; then
	extra_flags="$extra_flags --use-rewriter"
fi

parallel "(
	echo 'Starting {}'
	cp {} kernel_{/.}.cpp
	$original_folder/compile.sh kernel_{/.}.cpp
	# A small number seem to cause loops somewhere --- just want to get non-buggy results
	time timeout 60 $original_folder/run.sh $original_folder/$lmapper kernel_{/.}.bc --params-file $PWD/param.json $extra_flags
	if [[ \$? == 124 ]]; then
		# We timed out, so we should fall back to the mapper without
		# rewriting.  This would ideally happen interally within
		# flex, but it means the same thing happening here :)
		echo 'Rewriter timed out, running without rewriter.'
		# Put a tmeout on this also to avoid infinit e hanging.
		timeout 50 $original_folder/run.sh $original_folder/$lmapper kernel_{/.}.bc --params-file $PWD/param.json
		if [[ \$? == 124 ]]; then
			echo 'Subrewriter timed out'
		fi
	fi
	echo 'Done Building {/}')" ::: ${files[@]} &> run_output

success=$(grep -ce "Mapping:success" run_output || echo "")
fails=$(grep -ce "Mapping:fail" run_output || echo "")

mv run_output run_output.old

echo "Have $success successes, $fails fails"
