#!/bin/zsh

set -eu

if [[ $# -lt 1 ]]; then
	echo "Usage: $0 [folder to look in]+"
	exit 1
fi

typeset -a folders

# Get all the times, and put them in a file
while [[ $# -gt 0 ]]; do
	this_folder=$1
	folders+=( $this_folder/rewriter.times )

	grep -e applied --text $this_folder/rewriter.out > $this_folder/rewriter.times
	shift
done

# Call the plotting script with all of these.
python plot_compile_times_new.py ${folders[@]}
