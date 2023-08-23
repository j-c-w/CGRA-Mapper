#!/bin/zsh


set -eux

typeset -a print_only
typeset -a greedy

zparseopts -D -E -print-only=print_only -greedy=greedy

if [[ $# -lt 2 ]]; then
	echo "Usage: $0 <output directory> [ ... C files to explore ... ]"
	exit 1
fi


if [[ ${#print_only} -eq 0 ]]; then
	outdir=$1
	rm -rf $outdir
	mkdir -p $outdir
fi

shift

typeset -a files
while [[ $# -gt 0 ]]; do
	files+=( $1 )
	shift
done
i=0

# Go through each file and do the run sequence --- storing the outputs.
for file in ${files[@]}; do
	if [[ ${#print_only} -gt 0 ]]; then
		echo "Building a base for file $file, and comparing it to ${files[@]}"
	else
		echo "Using file $file as baseline now..."
		cp $file kernel.cpp
		./compile.sh kernel.cpp
		rm -f param.json
		./run.sh ../build/src/libmapperPass.so kernel.bc --build --params-file param_baseline.json &> $outdir/builder.$i
		./build_param.sh param_skeleton operations.json param.json
	fi

	# Now, go through every file and build:
	for file2 in ${files[@]}; do
		if [[ $file == $file2 ]]; then
			continue
		fi
		i=$((i + 1))
		if [[ ${#print_only} -gt 0 ]]; then
			echo "Comparing $file to $file2 (number $i)"
			continue
		fi
		cp $file2 kernel_internal.cpp
		./compile.sh kernel_internal.cpp
		if [[ ${#greedy} -gt 0 ]]; then
			control_flag="--use-greedy"
		else
			control_flag="--use-egraphs"
		fi
		(./run.sh ../build/src/libmapperPass.so kernel_internal.bc --params-file param.json $control_flag --dump-egraph &> $outdir/$i.stdout) || true

		if [[ -d extract ]]; then
			## expect this to be a directory unless wedidn't dump the egraphs
			# for some reason
			mv extract/* $outdir || true
		fi
		cp $file $outdir/$i.file1
		cp $file2 $outdir/$i.file2
		grep --text -e 'Mapping:' -e 'Placed' $outdir/$i.stdout > $outdir/$i.stdout_filtered || true

		python3 get_egraph_dumps.py $outdir/$i
		if [[ ! -f $outdir/$i.output.json ]]; then
			continue
			# No luck -- delete things to keep the folder clean
			rm $outdir/$i.file1
			rm $outdir/$i.file2
			rm $outdir/$i.stdout
			rm $outdir/$i.stdout_filtered
		fi
	done
done
