#!/bin/zsh
#SBATCH --cpus-per-task 40
#SBATCH --mem=600GB
#SBATCH -t 1-0:0

typeset -a rewriter_only
zparseopts -D -E -rewriter-only=rewriter_only

if [[ $# -lt 3 ]]; then
	echo "Usage: $0 <Architecture parameters file> <Loops benchmark directory> <output directory> [optional extra flags to pass to run_tests_against.sh]"
	exit 1
fi

pfile=$1
dir=$2
out=$3
shift 3
vs="$@"

echo "Running nix call"

cd ~/nix
./nix-user-chroot ~/.nix bash -c "
eval 'source ~/.profile';
cd ~/Projects/CGRA/CGRA-Mapper;
nix-shell shell.nix --run '
cd test;
./run_against_architectures.sh $pfile $dir $out $vs
'
"
