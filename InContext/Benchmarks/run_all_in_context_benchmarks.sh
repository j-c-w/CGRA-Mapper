#!/bin/zsh

set -eu

typeset -a plot_only
zparseopts -D -E -plot-only=plot_only

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 <output folder>"
	exit 1
fi

output_folder=$1
mkdir -p $output_folder

architectures=( ../../benchmark_scripts/architectures/sc-cgra.json )

if [[ ${#plot_only[@]} -eq 0 ]]; then
	for arch in ${architectures[@]}; do
		echo "Starting $arch"
		archname=$(basename $arch)
		if [[ $archname == *sc-cgra.json* ]]; then
			extra_flags="--use-stochastic"
		else
			extra_flags=""
		fi
		echo "Have $extra_flags"
		parallel ./run_in_context.sh $arch $output_folder/${archname}_{} {} $extra_flags ::: $(cat Working) > $output_folder/${archname}.stdout
	done
fi

python3.9 plot.py $output_folder A5_output
