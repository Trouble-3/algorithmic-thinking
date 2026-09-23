# First Feasible Value

**Input:** `low high threshold`, where feasibility is `x >= threshold`.  
**Output:** the first feasible value in `[low, high]`.

Example:

```text
0 100 37
```

Output:

```text
37
```

The predicate is monotone, so the search maintains a boundary invariant and runs in `O(log(high-low+1))` predicate calls.
