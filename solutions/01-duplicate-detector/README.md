# Duplicate Detector

**Input:** `n`, followed by `n` integers.  
**Output:** `YES` if any value occurs more than once, otherwise `NO`.

The solution stores each value in the repository's separate-chaining hash set. Expected time is `O(n)` under ordinary hashing assumptions; extra space is `O(n)`.

Example:

```text
6
4 9 1 4 7 2
```

Output:

```text
YES
```
