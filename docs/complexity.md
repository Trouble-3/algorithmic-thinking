# Complexity Notes

These are the intended asymptotic costs of the implementations in this repository.

| Structure / algorithm | Operation | Complexity |
|---|---|---|
| Hash set | average insert / contains | O(1) |
| Binary tree | traversal | O(n) |
| Binary tree | height | O(n) |
| Memoized Fibonacci | solve | O(n) |
| Coin-change DP | solve | O(amount × coins) |
| BFS | traversal | O(V + E) |
| Dijkstra + binary heap | shortest paths | O((V + E) log V) |
| Binary search | exact search | O(log n) |
| Min-heap | push / pop | O(log n) |
| Segment tree | range query | O(log n) |
| Segment tree | point update | O(log n) |
| Union-Find | amortized operation | near-constant in practice |

The point is not to memorize a table. Use it to connect a design choice to the operation that needs to become fast.
