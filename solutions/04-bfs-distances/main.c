#include <stdio.h>
#include <stdlib.h>
#include "graph.h"

int main(void) {
    size_t n, m, start;
    if (scanf("%zu %zu %zu", &n, &m, &start) != 3) return 1;
    Graph *g = graph_create(n);
    if (!g) return 1;
    for (size_t i = 0; i < m; ++i) {
        size_t u, v;
        if (scanf("%zu %zu", &u, &v) != 2 || graph_add_edge(g, u, v) == 0) { graph_destroy(g); return 1; }
    }
    int *dist = malloc(n * sizeof(*dist));
    if (!dist) { graph_destroy(g); return 1; }
    if (graph_bfs(g, start, dist) == 0) { free(dist); graph_destroy(g); return 1; }
    for (size_t i = 0; i < n; ++i) printf("%s%d", i ? " " : "", dist[i]);
    putchar('\n');
    free(dist);
    graph_destroy(g);
    return 0;
}
