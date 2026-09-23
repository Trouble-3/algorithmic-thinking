# Algorithmic Thinking — C Companion

A clean, testable C project inspired by the structure and problem-solving themes of Daniel Zingaro's *Algorithmic Thinking: A Problem-Based Introduction*.

The book is organized around eight core chapters: hash tables; trees and recursion; memoization and dynamic programming; graphs and breadth-first search; shortest paths in weighted graphs; binary search; heaps and segment trees; and union-find. This repository follows that same progression while using original implementations and examples.

> **Purpose:** practice algorithm design, data structures, complexity analysis, and implementation discipline.
>
> This repository is an independent companion project. It does not reproduce the book's text or source code.

## Chapters

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
│   └── demo.c
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

## License

MIT. See `LICENSE`.
