#include <assert.h>
#include <limits.h>
#include <stdio.h>

#include "binary_search.h"
#include "dijkstra.h"
#include "dp.h"
#include "graph.h"
#include "hash_set.h"
#include "heap.h"
#include "segment_tree.h"
#include "tree.h"
#include "union_find.h"

static int predicate(size_t x, void *ctx) {
    size_t threshold = *(size_t *)ctx;
    return x >= threshold;
}

static void test_hash(void) {
    HashSet *s = hash_set_create(8);
    assert(s);
    assert(hash_set_insert(s, 42) == 1);
    assert(hash_set_insert(s, 42) == 0);
    assert(hash_set_contains(s, 42));
    assert(!hash_set_contains(s, 7));
    hash_set_destroy(s);
}

static void test_tree(void) {
    TreeNode *root = tree_node_create(4);
    root->left = tree_node_create(2);
    root->right = tree_node_create(7);
    root->left->left = tree_node_create(1);
    root->left->right = tree_node_create(3);
    assert(tree_height(root) == 3);
    assert(tree_sum(root) == 17);
    int out[5], i = 0;
    tree_inorder(root, out, &i);
    assert(i == 5 && out[0] == 1 && out[4] == 7);
    tree_destroy(root);
}

static void test_dp(void) {
    assert(fibonacci_memo(0) == 0);
    assert(fibonacci_memo(20) == 6765);
    int coins[] = {1, 3, 4};
    assert(min_coins(coins, 3, 6) == 2);
    assert(min_coins(coins, 3, 2) == 2);
}

static void test_bfs(void) {
    Graph *g = graph_create(5);
    assert(g);
    graph_add_edge(g, 0, 1);
    graph_add_edge(g, 0, 2);
    graph_add_edge(g, 1, 3);
    graph_add_edge(g, 3, 4);
    int d[5];
    assert(graph_bfs(g, 0, d));
    assert(d[0] == 0 && d[3] == 2 && d[4] == 3);
    graph_destroy(g);
}

static void test_dijkstra(void) {
    WeightedGraph *g = weighted_graph_create(5);
    assert(g);
    weighted_graph_add_edge(g, 0, 1, 4);
    weighted_graph_add_edge(g, 0, 2, 1);
    weighted_graph_add_edge(g, 2, 1, 2);
    weighted_graph_add_edge(g, 1, 3, 1);
    weighted_graph_add_edge(g, 2, 3, 5);
    weighted_graph_add_edge(g, 3, 4, 3);
    long long d[5];
    assert(dijkstra(g, 0, d));
    assert(d[1] == 3 && d[3] == 4 && d[4] == 7);
    weighted_graph_destroy(g);
}

static void test_binary_search(void) {
    int a[] = {1, 3, 5, 7, 9};
    assert(binary_search(a, 5, 7) == 3);
    assert(binary_search(a, 5, 8) == -1);
    size_t threshold = 13;
    assert(first_true(0, 20, predicate, &threshold) == 13);
}

static void test_heap(void) {
    MinHeap *h = heap_create(2);
    assert(h);
    heap_push(h, 5); heap_push(h, 1); heap_push(h, 3);
    int x;
    heap_pop(h, &x); assert(x == 1);
    heap_pop(h, &x); assert(x == 3);
    heap_pop(h, &x); assert(x == 5);
    heap_destroy(h);
}

static void test_segment_tree(void) {
    int a[] = {2, 8, 1, 9, 4};
    SegmentTree *t = segment_tree_build(a, 5);
    assert(t);
    assert(segment_tree_query_max(t, 1, 4) == 9);
    assert(segment_tree_update(t, 2, 12));
    assert(segment_tree_query_max(t, 0, 3) == 12);
    segment_tree_destroy(t);
}

static void test_union_find(void) {
    UnionFind *uf = union_find_create(6);
    assert(uf);
    assert(union_find_union(uf, 0, 1));
    assert(union_find_union(uf, 1, 2));
    assert(union_find_connected(uf, 0, 2));
    assert(!union_find_connected(uf, 0, 5));
    union_find_destroy(uf);
}

int main(void) {
    test_hash();
    test_tree();
    test_dp();
    test_bfs();
    test_dijkstra();
    test_binary_search();
    test_heap();
    test_segment_tree();
    test_union_find();
    puts("All tests passed.");
    return 0;
}
