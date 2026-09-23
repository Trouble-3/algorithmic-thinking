#ifndef GRAPH_H
#define GRAPH_H

#include <stddef.h>

typedef struct Graph Graph;

Graph *graph_create(size_t vertices);
void graph_destroy(Graph *graph);
int graph_add_edge(Graph *graph, size_t from, size_t to);
int graph_bfs(const Graph *graph, size_t start, int *distance);

#endif
