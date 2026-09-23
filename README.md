# Algorithmic Thinking — C Companion

[![CI](https://github.com/OWNER/algorithmic-thinking/actions/workflows/ci.yml/badge.svg)](https://github.com/OWNER/algorithmic-thinking/actions/workflows/ci.yml)
[![C11](https://img.shields.io/badge/C-C11-blue)](#build)
[![License](https://img.shields.io/badge/license-MIT-green)](LICENSE)

> A structured C practice repository for algorithmic thinking, data structures, and problem solving.

A clean, testable C project inspired by the structure and problem-solving themes of Daniel Zingaro's *Algorithmic Thinking: A Problem-Based Introduction*.

The book is organized around eight core chapters: hash tables; trees and recursion; memoization and dynamic programming; graphs and breadth-first search; shortest paths in weighted graphs; binary search; heaps and segment trees; and union-find. This repository follows that same progression while using original implementations and examples.

> **Purpose:** practice algorithm design, data structures, complexity analysis, and implementation discipline.
>
> This repository is an independent companion project. It does not reproduce the book's text or source code.

## Chapters

The repository follows the book's eight-chapter progression: Hash Tables; Trees and Recursion; Memoization and Dynamic Programming; Graphs and Breadth-First Search; Shortest Paths in Weighted Graphs; Binary Search; Heaps and Segment Trees; and Union-Find. fileciteturn3file0L1-L7


| # | Topic | Main implementation |
|---|---|---|
| 01 | Hash Tables | integer hash set with separate chaining |
| 02 | Trees & Recursion | binary tree construction, traversal, height |
| 03 | Memoization & DP | memoized Fibonacci + bottom-up coin change |
| 04 | Graphs & BFS | adjacency-list graph + BFS distances |
| 05 | Weighted Shortest Paths | Dijkstra with a binary min-heap |
| 06 | Binary Search | classic search + first feasible value |
| 07 | Heaps & Segment Trees | min-heap + range-maximum segment tree |
| 08 | Union-Find | disjoint-set union with path compression |

## Design principles

- **Problem first:** every module is small enough to connect an implementation to a concrete algorithmic idea.
- **Complexity matters:** public APIs document the expected runtime where it is meaningful.
- **Tests are part of the project:** each chapter has focused tests.
- **C-first:** the project uses portable C11 and avoids non-standard compiler extensions.
- **Readable over clever:** names and invariants are kept explicit.

## Build

### CMake

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

### Direct GCC build

```bash
cc -std=c11 -Wall -Wextra -Wpedantic -Werror -Iinclude   src/*.c tests/test_all.c -o algorithmic_thinking_tests

./algorithmic_thinking_tests
```

## Run the example

```bash
cc -std=c11 -Wall -Wextra -Wpedantic -Iinclude   src/*.c examples/demo.c -o algorithmic_thinking_demo

./algorithmic_thinking_demo
```

## Repository layout

```text
algorithmic-thinking/
├── .github/workflows/ci.yml
├── docs/
│   ├── complexity.md
│   └── roadmap.md
├── examples/
│   ├── demo.c
│   └── chapter_demo.c
├── problems/
│   ├── 01-hash-tables.md
│   ├── 02-trees-recursion.md
│   ├── 03-dp.md
│   ├── 04-bfs.md
│   ├── 05-dijkstra.md
│   ├── 06-binary-search.md
│   ├── 07-heaps-segment-trees.md
│   └── 08-union-find.md
├── solutions/
│   ├── 01-duplicate-detector/
│   ├── 02-tree-aggregate/
│   ├── 03-min-coins/
│   ├── 04-bfs-distances/
│   ├── 05-dijkstra/
│   ├── 06-first-feasible/
│   ├── 07-range-max/
│   └── 08-dynamic-communities/
├── include/
│   ├── binary_search.h
│   ├── dijkstra.h
│   ├── dp.h
│   ├── graph.h
│   ├── hash_set.h
│   ├── heap.h
│   ├── segment_tree.h
│   ├── tree.h
│   └── union_find.h
├── src/
│   ├── binary_search.c
│   ├── dijkstra.c
│   ├── dp.c
│   ├── graph.c
│   ├── hash_set.c
│   ├── heap.c
│   ├── segment_tree.c
│   ├── tree.c
│   └── union_find.c
├── tests/
│   └── test_all.c
├── CMakeLists.txt
├── LICENSE
├── .clang-format
├── .gitignore
└── README.md
```

## Learning roadmap

1. Implement the baseline version.
2. Read the complexity notes before optimizing.
3. Add a small problem that exposes a limitation of the baseline.
4. Measure or reason about the new runtime.
5. Commit the change with a focused message.

Suggested commit style:

```text
feat(hash): add separate-chaining integer set
test(graph): cover unreachable BFS nodes
docs(dp): explain top-down vs bottom-up
refactor(heap): isolate sift-down operation
```

## Problems

Each chapter now has a small original practice problem in `problems/`. They are deliberately shorter than full competitive-programming statements so the repository stays focused on algorithmic thinking.

## Quality checks

Run the normal test suite with CMake:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

For AddressSanitizer and UndefinedBehaviorSanitizer:

```bash
./scripts/sanitize.sh
```

## Learning log

A useful way to turn this repository into a portfolio is to keep the code stable while recording what changed in your thinking:

- What was the naive approach?
- What operation was too slow?
- Which data structure or algorithm changed the bottleneck?
- What invariant makes the implementation correct?
- What is the expected complexity?
- What test case would break a careless implementation?

## Portfolio checklist

- [x] C11 implementation
- [x] Unit/integration-style tests
- [x] CMake build
- [x] GitHub Actions CI
- [x] Sanitizer script
- [x] Complexity notes
- [x] Chapter-by-chapter roadmap
- [x] Original practice problems
- [x] Eight runnable chapter solutions
- [x] Runnable examples
- [ ] Add measured benchmark results from your own machine
- [ ] Add your own solution notes / learning log
- [ ] Replace `OWNER` in README badges with your GitHub username

## License

MIT. See `LICENSE`.
