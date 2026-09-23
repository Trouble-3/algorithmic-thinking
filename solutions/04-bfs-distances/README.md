# BFS Distances

**Input:** `n m start`, followed by `m` directed edges `u v`.  
**Output:** shortest edge-count distance from `start` to every vertex; unreachable vertices are `-1`.

Example:

```text
5 5 0
0 1
0 2
1 3
2 3
3 4
```

Output:

```text
0 1 1 2 3
```

BFS processes each reachable vertex and edge once: `O(V + E)` time and `O(V)` auxiliary space.
