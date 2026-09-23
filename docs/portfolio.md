# Portfolio summary

## One-line description

C implementations of core algorithms and data structures, with tests, CI, sanitizers, complexity notes, and chapter-based practice.

## Skills demonstrated

- C11 and manual memory management
- data-structure design and API separation
- graph traversal and shortest paths
- dynamic programming and memoization
- binary search over monotone feasibility predicates
- heaps and range-query data structures
- disjoint-set union with path compression
- testing, sanitizers, CMake, Make, and GitHub Actions

## What to discuss in an interview

### 1. Hash tables

Explain why separate chaining changes the lookup problem from scanning every inserted value to searching one bucket on average, and discuss collision behavior.

### 2. BFS vs. Dijkstra

Explain why BFS works directly for unweighted shortest paths while weighted non-negative edges require a priority queue.

### 3. Memoization vs. bottom-up DP

Compare recursive state reuse with iterative state transitions, including stack usage and initialization requirements.

### 4. Binary search on the answer

Show how a monotone feasibility predicate turns an optimization problem into repeated yes/no checks.

### 5. Segment trees

Explain how interval aggregation supports logarithmic-time queries and point updates after linearithmic or linear-ish construction depending on implementation details.

### 6. Union-find

Explain the effect of path compression and union by size on repeated connectivity operations.

## GitHub About suggestion

> C implementations of core algorithms and data structures, with tests, CI, sanitizers, complexity notes, and chapter-based practice.

Suggested topics:

`c` `algorithms` `data-structures` `algorithmic-thinking` `dijkstra` `breadth-first-search` `binary-search` `dynamic-programming` `union-find` `segment-tree` `cmake`
