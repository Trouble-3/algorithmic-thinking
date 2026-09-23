# Dijkstra Shortest Paths

**Input:** `n m start`, followed by `m` directed weighted edges `u v w`. Edge weights must be non-negative.  
**Output:** shortest distances from `start`; unreachable vertices are printed as `LLONG_MAX` by the library's current API.

Example:

```text
4 5 0
0 1 7
0 2 2
2 1 3
1 3 1
2 3 9
```

Expected distances are `0 5 2 6`.

The implementation uses a binary min-heap. With adjacency lists and heap-based relaxation, the intended bound is `O((V + E) log V)`.
