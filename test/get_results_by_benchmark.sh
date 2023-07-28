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
# Diffferent scripts that call this keep this in different places.
if [[ -f $2.output ]]; then
    sizefile=$2.output
else
    sizefile=$2
fi
size=$(python3 $(dirname $(which $0))/get_number_of_operations.py "$(grep -m1 --text $sizefile -e 'Available ops are')")
echo "Has accelerator size $size"
python3 $(dirname $(which $0))/get_results_by_benchmark.py $1 <(grep --text $2 -e 'Mapping:' -e 'Done File') $3 --accelerator-size $size
