# 05 — Weighted Shortest Paths: Dijkstra

## Goal

Given a directed graph with non-negative edge weights, compute the shortest distance from one source to every reachable vertex.

## What to practice

- weighted graph modeling
- relaxation
- priority queues
- why BFS is not sufficient when edge weights matter

The implementation in `src/dijkstra.c` uses a binary min-heap. The book's Chapter 5 motivates this transition from counting edges to minimizing total edge weight. 
