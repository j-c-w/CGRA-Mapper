#!/bin/zsh

set -eu

typeset -a ruleset
zparseopts -D -E -- -ruleset+:=ruleset

# Get the location of the CGRA-Mapper-Rust.
cgra_mapper_rust=$(dirname $0)/../CGRA-Mapper-Rust

if [[ ! -d $cgra_mapper_rust ]]; then
	echo "Error: Unable to find the CGRA-Mapper-Rust folder"
	exit 1
fi

if [[ $# -ne 2 ]]; then
	echo "Usage: $0 <param.json> <output file> [--ruleset <name> (as many times as required)]"
	exit 1
fi

cd $cgra_mapper_rust

rule_flags=()
for rule in ${ruleset[@]}; do
	rule_flags+=(--rule $rule)
done

set -x
eval cargo run --example rewrite_rewrites $1 $2 "${ruleset[@]}"
