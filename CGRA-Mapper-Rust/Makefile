all: target/debug/libEggLib.so
	g++ src/EggLib.cpp ./target/debug/libEggLib.so -L ./target/debug -lm

target/debug/libEggLib.so: src/lib.rs Cargo.toml
	cargo build

clean:
	rm -rf target
