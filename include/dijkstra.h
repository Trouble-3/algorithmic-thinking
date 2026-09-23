#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <stddef.h>

typedef struct WeightedGraph WeightedGraph;

WeightedGraph *weighted_graph_create(size_t vertices);
void weighted_graph_destroy(WeightedGraph *graph);
int weighted_graph_add_edge(WeightedGraph *graph, size_t from, size_t to, int weight);
int dijkstra(const WeightedGraph *graph, size_t source, long long *distance);

#endif
