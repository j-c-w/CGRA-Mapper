#!/bin/bash
set -x

if [[ $# -ne 1 ]]; then
    echo "Usage: $0 <benchmarks folder>"
fi

rm -rf estimated_performance
mkdir -p estimated_performance

for file in $(find $1 -name "*.c"); do
    # Build the file into LLVM IR, then run LLVM MCA
    # on it.
	echo "Estimating performance on E21 for $file"
	basename=$(basename $file)
    ./install/bin/clang -target riscv32-unknown-linux-gnu $file -S -o- | ./install/bin/llvm-mca --march riscv32 -mcpu=sifive-e21 &> estimated_performance/${basename}.out
done

# Now get the estimate cycles from each file.
for file in $(find estimated_performance -name "*.out"); do
	echo "Looking at file $file"

	grep $file -e "Block RThroughput:" | cut -f2 -d':' > ${file/out/iters}
done
