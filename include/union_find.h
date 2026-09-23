#ifndef UNION_FIND_H
#define UNION_FIND_H

#include <stddef.h>

typedef struct UnionFind UnionFind;

UnionFind *union_find_create(size_t n);
void union_find_destroy(UnionFind *uf);
size_t union_find_find(UnionFind *uf, size_t x);
int union_find_union(UnionFind *uf, size_t a, size_t b);
int union_find_connected(UnionFind *uf, size_t a, size_t b);

#endif
