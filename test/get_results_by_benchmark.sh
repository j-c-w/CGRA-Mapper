#!/bin/zsh

# Wrapper for the python script because the files
# have some binary crap in them we need to strip out.
if [[ $# -ne 3 ]]; then
    echo "Usage: $0 <bname> <output file> <benchmark>"
    exit 1
fi

if [[ ! -f $2 ]]; then
    echo "File $s not found, skipping..."
    exit 1
fi

echo "File name is $2"
python $(dirname $(which $0))/get_results_by_benchmark.py $1 <(grep --text $2 -e 'Mapping:' -e 'Done File') $3