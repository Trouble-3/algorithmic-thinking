# Range Maximum Queries

**Input:** `n q`, an array of `n` integers, then `q` operations:

- `Q l r` — print the maximum on the inclusive range `[l, r]`;
- `U i value` — update index `i`.

Example:

```text
5 4
4 1 9 2 7
Q 1 3
U 2 0
Q 1 3
Q 0 4
```

Output:

```text
9
2
7
```

The segment tree supports both updates and range queries in `O(log n)` time.
