#include "graph.h"

#include <stdlib.h>

typedef struct Edge {
    size_t to;
    struct Edge *next;
} Edge;

struct Graph {
    size_t vertices;
    Edge **adj;
};

Graph *graph_create(size_t vertices) {
    Graph *graph = calloc(1, sizeof(*graph));
    if (!graph) return NULL;
    graph->vertices = vertices;
    graph->adj = calloc(vertices, sizeof(*graph->adj));
    if (vertices && !graph->adj) {
        free(graph);
        return NULL;
    }
    return graph;
}

void graph_destroy(Graph *graph) {
    if (!graph) return;
    for (size_t i = 0; i < graph->vertices; ++i) {
        Edge *cur = graph->adj[i];
        while (cur) {
            Edge *next = cur->next;
            free(cur);
            cur = next;
        }
    }
    free(graph->adj);
    free(graph);
}

int graph_add_edge(Graph *graph, size_t from, size_t to) {
    if (!graph || from >= graph->vertices || to >= graph->vertices) return 0;
    Edge *edge = malloc(sizeof(*edge));
    if (!edge) return 0;
    edge->to = to;
    edge->next = graph->adj[from];
    graph->adj[from] = edge;
    return 1;
}

int graph_bfs(const Graph *graph, size_t start, int *distance) {
    if (!graph || start >= graph->vertices || !distance) return 0;
    size_t *queue = malloc(graph->vertices * sizeof(*queue));
    if (graph->vertices && !queue) return 0;

    for (size_t i = 0; i < graph->vertices; ++i) distance[i] = -1;
    size_t head = 0, tail = 0;
    queue[tail++] = start;
    distance[start] = 0;

    while (head < tail) {
        size_t u = queue[head++];
        for (Edge *edge = graph->adj[u]; edge; edge = edge->next) {
            if (distance[edge->to] != -1) continue;
            distance[edge->to] = distance[u] + 1;
            queue[tail++] = edge->to;
        }
    }

    free(queue);
    return 1;
}
