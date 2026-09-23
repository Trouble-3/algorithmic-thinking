#include <stdio.h>

#include "binary_search.h"
#include "dp.h"
#include "graph.h"
#include "hash_set.h"
#include "union_find.h"

int main(void) {
    HashSet *seen = hash_set_create(16);
    hash_set_insert(seen, 10);
    hash_set_insert(seen, 20);
    printf("hash set contains 20: %s\n", hash_set_contains(seen, 20) ? "yes" : "no");
    hash_set_destroy(seen);

    printf("Fibonacci(10): %lld\n", fibonacci_memo(10));

    int values[] = {2, 4, 6, 8, 10};
    printf("index of 8: %d\n", binary_search(values, 5, 8));

    Graph *g = graph_create(4);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 1, 2);
    graph_add_edge(g, 2, 3);
    int distance[4];
    graph_bfs(g, 0, distance);
    printf("BFS distance 0 -> 3: %d\n", distance[3]);
    graph_destroy(g);

    UnionFind *uf = union_find_create(4);
    union_find_union(uf, 0, 1);
    union_find_union(uf, 1, 2);
    printf("0 and 2 connected: %s\n", union_find_connected(uf, 0, 2) ? "yes" : "no");
    union_find_destroy(uf);

    return 0;
}
