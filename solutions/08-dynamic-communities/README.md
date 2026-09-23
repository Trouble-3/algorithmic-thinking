# Dynamic Communities

**Input:** `n q`, then `q` operations:

- `U a b` — merge the communities containing `a` and `b`;
- `Q a b` — print whether `a` and `b` currently belong to the same community.

Example:

```text
5 5
U 0 1
U 1 2
Q 0 2
Q 0 4
U 3 4
```

Output:

```text
YES
NO
```

The implementation combines union by size with path compression. Its amortized cost is effectively constant per operation for practical purposes (formally, inverse-Ackermann time).
