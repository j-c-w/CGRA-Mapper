all: target/release/libEggLib.so
	g++ src/EggLib.cpp ./target/release/libEggLib.so -L ./target/release -lm

target/release/libEggLib.so: src/lib.rs Cargo.toml
	cargo build --release

clean:
	rm -rf target
