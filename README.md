# Algorithmic Thinking — C Companion

[![CI](https://github.com/YOUR_USERNAME/algorithmic-thinking/actions/workflows/ci.yml/badge.svg)](https://github.com/YOUR_USERNAME/algorithmic-thinking/actions/workflows/ci.yml)
[![C11](https://img.shields.io/badge/C-C11-blue)](#build)
[![CMake](https://img.shields.io/badge/build-CMake-informational)](#build)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)

> A portfolio-ready C project for learning how algorithms turn bottlenecks into data structures, invariants, and efficient solutions.

This repository is an independent companion project inspired by the chapter progression and problem-based approach of Daniel Zingaro's *Algorithmic Thinking: A Problem-Based Introduction*.

The source material organizes the core topics as hash tables; trees and recursion; memoization and dynamic programming; graphs and breadth-first search; shortest paths in weighted graphs; binary search; heaps and segment trees; and union-find. This repository follows that progression with original code, exercises, tests, and runnable solutions. fileciteturn4file0L1-L8

## Why this repository exists

The goal is not to collect implementations. It is to show the reasoning loop behind them:

```text
problem
   ↓
naive approach
   ↓
identify the bottleneck
   ↓
choose a data structure / algorithm
   ↓
state the invariant
   ↓
prove the complexity
   ↓
test edge cases
```

The project deliberately keeps each implementation small enough to read from top to bottom.

## Chapter map

| # | Topic | Core implementation | Runnable solution |
|---|---|---|---|
| 01 | Hash Tables | separate-chaining integer hash set | duplicate detector |
| 02 | Trees & Recursion | binary tree + recursive traversal | tree aggregate |
| 03 | Memoization & DP | memoized Fibonacci + coin DP | minimum coins |
| 04 | Graphs & BFS | adjacency list + BFS | distance from source |
| 05 | Weighted Shortest Paths | Dijkstra + min-heap | shortest routes |
| 06 | Binary Search | exact search + first-feasible search | threshold search |
| 07 | Heaps & Segment Trees | min-heap + range maximum tree | range maximum |
| 08 | Union-Find | path compression + union by size | dynamic communities |

The book describes BFS as a shortest-path tool for the appropriate unweighted setting, Dijkstra for weighted shortest paths, binary search as a way to reduce some optimization tasks to feasibility checks, segment trees for range queries, and union-find for maintaining equivalent sets. The project uses the same conceptual progression while keeping its own exercises and implementations. fileciteturn4file1L1-L8 fileciteturn4file3L1-L8 fileciteturn4file7L1-L8

## Repository structure

```text
algorithmic-thinking/
├── .github/                  # CI + contribution templates
├── benchmarks/               # generated workloads + benchmark runner
├── docs/                     # architecture, diagrams, complexity, roadmap, learning log
├── examples/                 # small runnable demonstrations
├── include/                  # public C headers
├── problems/                 # original practice problem statements
├── solutions/                # eight chapter-aligned runnable solutions
├── src/                      # algorithm/data-structure implementations
├── tests/                    # project test suite
├── CMakeLists.txt
├── Makefile
├── LICENSE
└── README.md
```

## Build

### CMake

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

### Make

```bash
make
make test
make sanitize
```

## Run a chapter solution

After building, for example:

```bash
./build/solution_04_bfs_distances
./build/solution_05_dijkstra
./build/solution_07_range_max
```

Every directory under `solutions/` contains its own short problem statement, input/output contract, example, and complexity note.

## Quality checks

CI runs two layers:

1. a normal C11 build and test suite;
2. AddressSanitizer + UndefinedBehaviorSanitizer builds.

Locally:

```bash
ctest --test-dir build --output-on-failure
./scripts/sanitize.sh
```

## Benchmarks

The benchmark plan is intentionally conservative: timings are machine-dependent, so the project focuses on reproducibility and growth trends rather than publishing arbitrary universal numbers.

```bash
make benchmark
```

See [`benchmarks/README.md`](benchmarks/README.md) and [`docs/diagrams.md`](docs/diagrams.md).

## Learning log

The most portfolio-relevant part is the reasoning record. For each chapter, write down:

- the naive approach;
- the bottleneck;
- the invariant;
- the chosen optimization;
- time and space complexity;
- one edge case that influenced the implementation.

Template: [`docs/learning-log.md`](docs/learning-log.md)

Progress tracker: [`docs/progress.md`](docs/progress.md)

Contribution guide: [`CONTRIBUTING.md`](CONTRIBUTING.md)

## What makes this portfolio-friendly

- **8 coherent topics** instead of unrelated snippets.
- **Original practice tasks** rather than copied problem statements.
- **Reusable library code** separated from executable solutions.
- **Tests + sanitizers + CI** instead of “it compiles on my machine”.
- **Complexity documentation** beside the implementations.
- **Learning log** that shows algorithmic reasoning, not only syntax.
- **Small commits can be demonstrated** with the suggested commit style below.

Suggested commit style:

```text
feat(hash): add separate-chaining integer set
test(graph): cover unreachable BFS nodes
docs(dp): explain top-down vs bottom-up
refactor(heap): isolate sift-down operation
```

## Portfolio checklist

- [x] C11 implementation
- [x] CMake build
- [x] Unit/integration-style tests
- [x] GitHub Actions CI
- [x] Sanitizer workflow
- [x] Complexity notes
- [x] Chapter roadmap
- [x] Original practice problems
- [x] Eight runnable solutions
- [x] Architecture documentation
- [x] Benchmark entry point
- [x] Learning-log template
- [ ] Replace `YOUR_USERNAME` in the badges
- [ ] Fill in personal learning notes
- [ ] Add benchmark results from your own machine

## Attribution and scope

This is an independent learning repository. It follows the book's high-level chapter structure and algorithmic themes but does not reproduce the book's prose or source code. The book's problem credits identify the original sources of the competitive-programming problems used there; this repository instead uses newly written practice tasks. fileciteturn5file1L1-L8

## License

MIT. See [`LICENSE`](LICENSE).
