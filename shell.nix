{ pkgs ? import<nixpkgs> {} }:

with pkgs;

mkShell {
	buildInputs = [ llvm clang cmake ctags gdb ];
}
