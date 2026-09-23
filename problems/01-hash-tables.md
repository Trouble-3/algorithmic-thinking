# 01 — Hash Tables: Duplicate Detector

## Goal

Given a stream of integers, determine whether a value has appeared before.

## What to practice

- hashing
- buckets
- collision handling
- average-case lookup
- recognizing repeated linear searches as a performance bottleneck

## Suggested progression

1. Write the straightforward `O(n²)` comparison solution.
2. Replace repeated searches with the hash set from `src/hash_set.c`.
3. Compare the two designs on increasing input sizes.
4. Explain why the hash-table solution is expected to scale better.

This is an original practice exercise inspired by the hash-table problem-solving theme of Chapter 1; it is not a reproduction of a book problem.
