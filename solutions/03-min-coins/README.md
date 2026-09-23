# Minimum Coins

**Input:** `k amount`, followed by `k` positive coin denominations.  
**Output:** the minimum number of coins needed to make `amount`, or `-1` if impossible.

Example:

```text
3 11
1 5 7
```

Output:

```text
3
```

The bottom-up recurrence computes each amount from smaller amounts. Time is `O(k * amount)` and space is `O(amount)`.
