# Benchmark Plan

The project is intentionally small, so benchmarks are kept as a reproducible plan rather than pretending that one machine's timings are universal.

## What to measure

| Topic | Baseline | Optimized structure |
|---|---|---|
| Hashing | repeated linear scan | hash set |
| DP | naive recursive recurrence | memoization / DP |
| Graphs | repeated exploration | BFS |
| Shortest paths | repeated relaxation | Dijkstra + heap |
| Search | linear scan | binary search |
| Minimum/maximum | repeated scan | heap |
| Range queries | scan each range | segment tree |

## Method

- compile with the same optimization level;
- increase input size geometrically;
- run each case multiple times;
- report the median;
- record compiler and machine details;
- compare growth trends, not isolated milliseconds.

The purpose is to connect asymptotic reasoning to observed behavior. The book also uses execution time as an intuition-building tool while emphasizing algorithmic efficiency.
