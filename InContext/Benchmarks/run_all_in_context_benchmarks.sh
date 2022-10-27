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

architectures=( ../../benchmark_scripts/architectures/cca.json ../../benchmark_scripts/architectures/maeri.json ../../benchmark_scripts/architectures/revamp.json ../../benchmark_scripts/architectures/sc-cgra.json )

if [[ ${#plot_only[@]} -eq 0 ]]; then
	for arch in ${architectures[@]}; do
		archname=$(basename $arch)
		parallel ./run_in_context.sh $arch $output_folder/${archname}_{} {} ::: $(cat Working) > $output_folder/${archname}.stdout
	done
fi

# TOTO -- plot
