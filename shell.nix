{ pkgs ? import<nixpkgs> {} }:

with pkgs;

mkShell {
	buildInputs = [
		llvm clang cmake ctags gdb cargo rustc CoinMP 
	# Script deps
	zsh python39 python39Packages.apsw python39Packages.numpy python39Packages.matplotlib parallel 
	# TOols to make developement within this shell bearable
	git vim ];
	SHELL_NAME="CGRA-Mapper";
}
