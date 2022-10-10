#!/bin/zsh
#SBATCH --cpus-per-task 40
#SBATCH --mem=400GB
#SBATCH -t 360 

typeset -a run_individual_rulesets
zparseopts -D -E -- -run-individual-rulesets=run_individual_rulesets

if [[ $# -ne 4 ]]; then
	echo "Usage: $0 <loop name> <loop number> <loops folder> <reduction rate>"
	echo "Note: this should only be issued as a slurm job -- it doesn't issue the slurm jobs itself"
	exit 1
fi

run_individual_rulesets_flag=""
if [[ ${#run_individual_rulesets} -gt 0 ]]; then
	run_individual_rulesets_flag="--run-individual-rulesets"
fi

mkdir -p temp_slurm
loopname=$1
loopno=$2
loops_folder=$3
reduction_rate=$4 # Float from 0.0 to 1.0 --- how many loops to try
# and compile to each design to save time.

cd ~/nix
./nix-user-chroot ~/.nix bash -c "
source ~/.bashrc
cd ~/Projects/CGRA/CGRA-Mapper
nix-shell shell.nix --run '
set -x
cd test
./run_all_benchmarks.sh $run_individual_rulesets_flag $reduction_rate $loops_folder temp_slurm/temp$loopno --gather-only --test-loops $loopname
'
"
