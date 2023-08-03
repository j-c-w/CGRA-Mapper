{ pkgs ? import<nixpkgs> { } }:

with pkgs;

mkShell {
	buildInputs = [
		llvm clang
		cmake ctags gdb cargo rustc CoinMP cbc
		# Deps for the DFG Mapping
		tclap
	# Script deps
	zsh parallel 
	# python39 python39Packages.apsw python39Packages.numpy python39Packages.matplotlib
	# TOols to make developement within this shell bearable
	git

	# Requirements for RL
	conda
];
	SHELL_NAME="CGRA-Mapper";
	shellHook = ''
	export PATH=$PATH:$PWD/bin
		'';
}
