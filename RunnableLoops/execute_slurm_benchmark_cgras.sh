#!/bin/zsh
#SBATCH --cpus-per-task 40
#SBATCH --mem=400GB
#SBATCH -t 360


if [[ $# -ne 4 ]]; then
    echo "Usage: $0 <loop name> <loop number> <loops folder> <reduction rate>"
    exit 1
fi

mkdir -p temp_slurm
loopname=$1
loopno=$2
loops_folder=$3
reduction_rate=$4

cd ~/nix
./nix-user-chroot ~/.nix bash -c "
source ~/.bashrc
cd ~/Projects/CGRA/CGRA-Mapper
nix-shell shell.nix --run '
cd RunnableLoops
set -x
./benchmark_cgras.sh $reduction_rate $loops_folder temp_slurm/temp$loopno --gather-only --test-loops $loopname
'
"
