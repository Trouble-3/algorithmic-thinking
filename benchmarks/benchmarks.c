#include "graph.h"
#include "hash_set.h"
#include "segment_tree.h"
#include "union_find.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

static double elapsed_seconds(clock_t start, clock_t end) {
    return (double)(end - start) / (double)CLOCKS_PER_SEC;
}

static void bench_hash(size_t n) {
    HashSet *set = hash_set_create(n * 2 + 1);
    if (!set) {
        fprintf(stderr, "hash allocation failed\n");
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();
    for (size_t i = 0; i < n; ++i) {
        if (!hash_set_insert(set, (int)i)) {
            fprintf(stderr, "hash insert failed\n");
            hash_set_destroy(set);
            exit(EXIT_FAILURE);
        }
    }
    volatile size_t hits = 0;
    for (size_t i = 0; i < n; ++i) {
        hits += (size_t)hash_set_contains(set, (int)i);
    }
    clock_t end = clock();
    (void)hits;

    printf("hash_set,%zu,%.6f\n", n, elapsed_seconds(start, end));
    hash_set_destroy(set);
}

static void bench_bfs(size_t n) {
    Graph *graph = graph_create(n);
    if (!graph) {
        fprintf(stderr, "graph allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i + 1 < n; ++i) {
        if (!graph_add_edge(graph, i, i + 1)) {
            fprintf(stderr, "graph edge insertion failed\n");
            graph_destroy(graph);
            exit(EXIT_FAILURE);
        }
    }

    int *distance = malloc(n * sizeof(*distance));
    if (!distance) {
        fprintf(stderr, "distance allocation failed\n");
        graph_destroy(graph);
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();
    if (!graph_bfs(graph, 0, distance)) {
        fprintf(stderr, "BFS failed\n");
        free(distance);
        graph_destroy(graph);
        exit(EXIT_FAILURE);
    }
    clock_t end = clock();

    printf("bfs_path,%zu,%.6f\n", n, elapsed_seconds(start, end));
    free(distance);
    graph_destroy(graph);
}

static void bench_segment_tree(size_t n) {
    int *values = malloc(n * sizeof(*values));
    if (!values) {
        fprintf(stderr, "values allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (size_t i = 0; i < n; ++i) {
        values[i] = (int)(i % 1000);
    }

    SegmentTree *tree = segment_tree_build(values, n);
    if (!tree) {
        fprintf(stderr, "segment tree allocation failed\n");
        free(values);
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();
    volatile long long checksum = 0;
    for (size_t i = 0; i + 32 < n; i += 17) {
        checksum += segment_tree_query_max(tree, i, i + 31);
        if (!segment_tree_update(tree, i, values[i] + 1)) {
            fprintf(stderr, "segment tree update failed\n");
            segment_tree_destroy(tree);
            free(values);
            exit(EXIT_FAILURE);
        }
    }
    clock_t end = clock();
    (void)checksum;

    printf("segment_tree,%zu,%.6f\n", n, elapsed_seconds(start, end));
    segment_tree_destroy(tree);
    free(values);
}

static void bench_union_find(size_t n) {
    UnionFind *uf = union_find_create(n);
    if (!uf) {
        fprintf(stderr, "union-find allocation failed\n");
        exit(EXIT_FAILURE);
    }

    clock_t start = clock();
    for (size_t i = 1; i < n; ++i) {
        if (!union_find_union(uf, i - 1, i)) {
            fprintf(stderr, "union failed\n");
            union_find_destroy(uf);
            exit(EXIT_FAILURE);
        }
    }
    volatile size_t connected = 0;
    for (size_t i = 0; i < n; i += 2) {
        connected += (size_t)union_find_connected(uf, 0, i);
    }
    clock_t end = clock();
    (void)connected;

    printf("union_find,%zu,%.6f\n", n, elapsed_seconds(start, end));
    union_find_destroy(uf);
}

int main(void) {
    const size_t sizes[] = {1000, 10000, 100000};
    const size_t count = sizeof(sizes) / sizeof(sizes[0]);

    puts("benchmark,size,cpu_seconds");
    for (size_t i = 0; i < count; ++i) {
        bench_hash(sizes[i]);
        bench_bfs(sizes[i]);
        bench_segment_tree(sizes[i]);
        bench_union_find(sizes[i]);
    }
    return 0;
}
