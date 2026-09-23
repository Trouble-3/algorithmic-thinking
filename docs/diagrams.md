# Algorithm diagrams

These diagrams are deliberately small: they show the control flow and the invariant to keep in mind while reading the C implementation.

## Breadth-first search

```mermaid
flowchart TD
    A[Start at source] --> B[Push source into queue]
    B --> C{Queue empty?}
    C -- No --> D[Pop vertex u]
    D --> E[Inspect neighbors of u]
    E --> F{Neighbor visited?}
    F -- No --> G[Set distance = dist[u] + 1]
    G --> H[Push neighbor]
    H --> E
    F -- Yes --> E
    E --> C
    C -- Yes --> I[All reachable distances known]
```

Invariant: when a vertex is first discovered, its BFS distance is the minimum number of edges from the source in an unweighted graph.

## Dijkstra + min-heap

```mermaid
flowchart TD
    A[Initialize dist[source] = 0] --> B[Push source into min-heap]
    B --> C{Heap empty?}
    C -- No --> D[Pop smallest tentative distance]
    D --> E{Entry stale?}
    E -- Yes --> C
    E -- No --> F[Relax outgoing edges]
    F --> G{Found shorter path?}
    G -- Yes --> H[Update distance]
    H --> I[Push new priority]
    I --> F
    G -- No --> F
    F --> C
    C -- Yes --> J[Shortest distances finalized]
```

Invariant: a non-stale minimum-distance entry is the next vertex whose shortest distance can be finalized under the non-negative-edge assumption.

## Union-find

```mermaid
flowchart LR
    A[find(x)] --> B{parent[x] == x?}
    B -- Yes --> C[Return root]
    B -- No --> D[Find parent root]
    D --> E[Compress path]
    E --> C

    F[union(a,b)] --> G[Find roots]
    G --> H{Same root?}
    H -- Yes --> I[No change]
    H -- No --> J[Attach smaller tree to larger tree]
```

Invariant: every element belongs to exactly one rooted component, and `parent[x]` eventually leads to that component's representative.

## Segment tree range maximum

```mermaid
flowchart TD
    A[Query range L..R] --> B{Current node fully covered?}
    B -- Yes --> C[Return stored maximum]
    B -- No --> D{Disjoint?}
    D -- Yes --> E[Return -infinity]
    D -- No --> F[Query left child]
    F --> G[Query right child]
    G --> H[Return max(left,right)]
```

Invariant: every tree node stores the maximum value of its represented interval.
