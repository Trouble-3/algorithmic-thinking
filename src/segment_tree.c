#include "segment_tree.h"

#include <limits.h>
#include <stdlib.h>

struct SegmentTree {
    size_t n;
    int *tree;
};

static void build(int *tree, const int *a, size_t node, size_t l, size_t r) {
    if (r - l == 1) { tree[node] = a[l]; return; }
    size_t m = l + (r - l) / 2;
    build(tree, a, node * 2, l, m);
    build(tree, a, node * 2 + 1, m, r);
    tree[node] = tree[node * 2] > tree[node * 2 + 1] ? tree[node * 2] : tree[node * 2 + 1];
}

static void update(int *tree, size_t node, size_t l, size_t r, size_t index, int value) {
    if (r - l == 1) { tree[node] = value; return; }
    size_t m = l + (r - l) / 2;
    if (index < m) update(tree, node * 2, l, m, index, value);
    else update(tree, node * 2 + 1, m, r, index, value);
    tree[node] = tree[node * 2] > tree[node * 2 + 1] ? tree[node * 2] : tree[node * 2 + 1];
}

static int query(const int *tree, size_t node, size_t l, size_t r, size_t ql, size_t qr) {
    if (qr <= l || r <= ql) return INT_MIN;
    if (ql <= l && r <= qr) return tree[node];
    size_t m = l + (r - l) / 2;
    int a = query(tree, node * 2, l, m, ql, qr);
    int b = query(tree, node * 2 + 1, m, r, ql, qr);
    return a > b ? a : b;
}

SegmentTree *segment_tree_build(const int *values, size_t n) {
    if (!values || n == 0) return NULL;
    SegmentTree *t = malloc(sizeof(*t));
    if (!t) return NULL;
    t->n = n;
    t->tree = malloc(4 * n * sizeof(*t->tree));
    if (!t->tree) { free(t); return NULL; }
    build(t->tree, values, 1, 0, n);
    return t;
}

void segment_tree_destroy(SegmentTree *tree) {
    if (!tree) return;
    free(tree->tree);
    free(tree);
}

int segment_tree_update(SegmentTree *tree, size_t index, int value) {
    if (!tree || index >= tree->n) return 0;
    update(tree->tree, 1, 0, tree->n, index, value);
    return 1;
}

int segment_tree_query_max(const SegmentTree *tree, size_t left, size_t right) {
    if (!tree || left >= right || right > tree->n) return INT_MIN;
    return query(tree->tree, 1, 0, tree->n, left, right);
}
