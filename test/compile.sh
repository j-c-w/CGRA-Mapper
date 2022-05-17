set -e

if [[ $# -ne 1 ]]; then
	echo "Usage: $0 <filename>"
	exit 1
fi

clang -emit-llvm -fno-unroll-loops -O3 -o ${1/.cpp/}.bc -c ${1}
#llvm-dis fir.bc -o fir.ll
