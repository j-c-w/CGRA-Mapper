#!/bin/bash

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <output file from CGRA benchmark>"
    exit 0
fi

rm -rf cgra_performances
mkdir cgra_performances

# Get all the successes, but only the successes:
for file in $(find $1 -name *.egraphs.output); do
    echo "Inspecting $file"
    # Note that these are in order, so we can seperate them
    # as the first kernel_X.bc corresponds to the frist II.
    iis=( $(grep --text $file -e "Mapping:success" -B2 | grep --text -e II | cut -f2 -d' ') )
    kernels=( $(grep --text $file -e "Mapping:success" -A6 | grep --text -e Building | cut -f2 -d' ') )
    bfile=$(basename $file)
    target=cgra_performances/${bfile/egraphs.output/output}
    echo "Putting perfomacne in $target"
    echo -n "" > $target

    for i in ${!iis[@]}; do
        echo "${kernels[$i]},${iis[$i]}" >> $target
    done
done
