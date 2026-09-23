#include "union_find.h"

#include <stdlib.h>

struct UnionFind {
    size_t *parent;
    size_t *size;
    size_t n;
};

UnionFind *union_find_create(size_t n) {
    UnionFind *uf = malloc(sizeof(*uf));
    if (!uf) return NULL;
    uf->n = n;
    uf->parent = malloc(n * sizeof(*uf->parent));
    uf->size = malloc(n * sizeof(*uf->size));
    if (n && (!uf->parent || !uf->size)) {
        free(uf->parent); free(uf->size); free(uf); return NULL;
    }
    for (size_t i = 0; i < n; ++i) { uf->parent[i] = i; uf->size[i] = 1; }
    return uf;
}

void union_find_destroy(UnionFind *uf) {
    if (!uf) return;
    free(uf->parent);
    free(uf->size);
    free(uf);
}

size_t union_find_find(UnionFind *uf, size_t x) {
    if (!uf || x >= uf->n) return (size_t)-1;
    if (uf->parent[x] != x) uf->parent[x] = union_find_find(uf, uf->parent[x]);
    return uf->parent[x];
}

int union_find_union(UnionFind *uf, size_t a, size_t b) {
    if (!uf || a >= uf->n || b >= uf->n) return 0;
    a = union_find_find(uf, a);
    b = union_find_find(uf, b);
    if (a == b) return 0;
    if (uf->size[a] < uf->size[b]) { size_t t = a; a = b; b = t; }
    uf->parent[b] = a;
    uf->size[a] += uf->size[b];
    return 1;
}

int union_find_connected(UnionFind *uf, size_t a, size_t b) {
    if (!uf || a >= uf->n || b >= uf->n) return 0;
    return union_find_find(uf, a) == union_find_find(uf, b);
}
