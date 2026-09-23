#include <stdio.h>
#include <stdlib.h>
#include "dijkstra.h"

int main(void) {
    size_t n, m, start;
    if (scanf("%zu %zu %zu", &n, &m, &start) != 3) return 1;
    WeightedGraph *g = weighted_graph_create(n);
    if (!g) return 1;
    for (size_t i = 0; i < m; ++i) {
        size_t u, v; int w;
        if (scanf("%zu %zu %d", &u, &v, &w) != 3 || weighted_graph_add_edge(g, u, v, w) == 0) { weighted_graph_destroy(g); return 1; }
    }
    long long *dist = malloc(n * sizeof(*dist));
    if (!dist) { weighted_graph_destroy(g); return 1; }
    if (dijkstra(g, start, dist) == 0) { free(dist); weighted_graph_destroy(g); return 1; }
    for (size_t i = 0; i < n; ++i) printf("%s%lld", i ? " " : "", dist[i]);
    putchar('\n');
    free(dist);
    weighted_graph_destroy(g);
    return 0;
}
