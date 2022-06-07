{ pkgs ? import<nixpkgs> {} }:

with pkgs;

mkShell {
	buildInputs = [ llvm clang cmake ctags gdb cargo rustc CoinMP 
	  python39 python39Packages.apsw vim parallel ];
	SHELL_NAME="CGRA-Mapper";
}
