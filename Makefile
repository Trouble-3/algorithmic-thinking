.PHONY: all build test clean sanitize benchmark

all: build

build:
	cmake -S . -B build
	cmake --build build

test: build
	ctest --test-dir build --output-on-failure

sanitize:
	./scripts/sanitize.sh

benchmark:
	./benchmarks/run.sh

clean:
	rm -rf build
