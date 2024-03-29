#!/bin/zsh

typeset -a stochastic
zparseopts -D -E -- -use-stochastic=stochastic

max_time=600

# This benchmarks a single benchmark against all the 
# different compiler options.
if [[ $# -lt 3 ]]; then
	echo "Usage: $0 <architecture file> <output folder> <benchmark folder> [extra flags]"
	echo "Got $#"
	exit 1
fi

archfile=$PWD/$1
outfile=$PWD/$2
bfolder=$3

extra_flags=""
if [[ ${#stochastic} -gt 0 ]]; then
	extra_flags=( --ruleset stochastic )
fi

mkdir -p $outfile

pushd $bfolder
## Do the non-LLVM ones first.
../compile.sh flexc_loop.c
echo "Starting OpenCGRA"
timeout $max_time ../run.sh ../../../build/src/libmapperPass.so flexc_loop.c.bc --params-file $archfile &> $outfile/opencgra.stdout
echo "Starting Greedy"
timeout $max_time ../run.sh ../../../build/src/libmapperPass.so flexc_loop.c.bc --params-file $archfile --use-greedy ${extra_flags[@]} &> $outfile/greedy.stdout
echo "Starting FlexC"
timeout $max_time ../run.sh ../../../build/src/libmapperPass.so flexc_loop.c.bc --params-file $archfile --use-rewriter ${extra_flags[@]} &> $outfile/flexc.stdout
echo "Starting LLVM"
../compile.sh flexc_loop.c --use-llvm-cannonicalizer
timeout $max_time ../run.sh ../../../build/src/libmapperPass.so flexc_loop.c.bc --params-file $archfile &> $outfile/llvm.stdout

# Go through and get the results from each.
get_results() {
	local infile=$1
	local mode=$2 # llvm/opencgra/greed/flexc
	local out=$3

	result=$(grep --binary-files=text -e '^II:' $infile || echo "Failed")
	echo "$mode,$result">> $out
}

echo -n "" > $outfile/data

get_results $outfile/opencgra.stdout opencgra $outfile/data
get_results $outfile/greedy.stdout greedy $outfile/data
get_results $outfile/flexc.stdout flexc $outfile/data
get_results $outfile/llvm.stdout llvm $outfile/data
