#include "dijkstra.h"

#include <limits.h>
#include <stdlib.h>

typedef struct WEdge {
    size_t to;
    int weight;
    struct WEdge *next;
} WEdge;

struct WeightedGraph {
    size_t vertices;
    WEdge **adj;
};

typedef struct {
    size_t vertex;
    long long distance;
} HeapNode;

typedef struct {
    HeapNode *data;
    size_t size;
    size_t capacity;
} NodeHeap;

static int heap_push(NodeHeap *h, HeapNode node) {
    if (h->size == h->capacity) {
        size_t cap = h->capacity ? h->capacity * 2 : 8;
        HeapNode *p = realloc(h->data, cap * sizeof(*p));
        if (!p) return 0;
        h->data = p;
        h->capacity = cap;
    }
    size_t i = h->size++;
    h->data[i] = node;
    while (i) {
        size_t p = (i - 1) / 2;
        if (h->data[p].distance <= h->data[i].distance) break;
        HeapNode t = h->data[p]; h->data[p] = h->data[i]; h->data[i] = t;
        i = p;
    }
    return 1;
}

static int heap_pop(NodeHeap *h, HeapNode *out) {
    if (!h->size) return 0;
    *out = h->data[0];
    h->data[0] = h->data[--h->size];
    size_t i = 0;
    while (1) {
        size_t l = 2*i+1, r = l+1, s = i;
        if (l < h->size && h->data[l].distance < h->data[s].distance) s = l;
        if (r < h->size && h->data[r].distance < h->data[s].distance) s = r;
        if (s == i) break;
        HeapNode t = h->data[i]; h->data[i] = h->data[s]; h->data[s] = t;
        i = s;
    }
    return 1;
}

WeightedGraph *weighted_graph_create(size_t vertices) {
    WeightedGraph *g = calloc(1, sizeof(*g));
    if (!g) return NULL;
    g->vertices = vertices;
    g->adj = calloc(vertices, sizeof(*g->adj));
    if (vertices && !g->adj) { free(g); return NULL; }
    return g;
}

void weighted_graph_destroy(WeightedGraph *g) {
    if (!g) return;
    for (size_t i = 0; i < g->vertices; ++i) {
        WEdge *e = g->adj[i];
        while (e) { WEdge *next = e->next; free(e); e = next; }
    }
    free(g->adj);
    free(g);
}

int weighted_graph_add_edge(WeightedGraph *g, size_t from, size_t to, int weight) {
    if (!g || from >= g->vertices || to >= g->vertices || weight < 0) return 0;
    WEdge *e = malloc(sizeof(*e));
    if (!e) return 0;
    e->to = to; e->weight = weight; e->next = g->adj[from]; g->adj[from] = e;
    return 1;
}

int dijkstra(const WeightedGraph *g, size_t source, long long *distance) {
    if (!g || source >= g->vertices || !distance) return 0;
    for (size_t i = 0; i < g->vertices; ++i) distance[i] = LLONG_MAX;
    distance[source] = 0;

    NodeHeap heap = {0};
    if (!heap_push(&heap, (HeapNode){source, 0})) return 0;

    HeapNode current;
    while (heap_pop(&heap, &current)) {
        if (current.distance != distance[current.vertex]) continue;
        for (WEdge *e = g->adj[current.vertex]; e; e = e->next) {
            long long next = current.distance + e->weight;
            if (next < distance[e->to]) {
                distance[e->to] = next;
                if (!heap_push(&heap, (HeapNode){e->to, next})) {
                    free(heap.data);
                    return 0;
                }
            }
        }
    }
    free(heap.data);
    return 1;
}
