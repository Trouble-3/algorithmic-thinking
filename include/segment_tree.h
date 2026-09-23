#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include <stddef.h>

typedef struct SegmentTree SegmentTree;

SegmentTree *segment_tree_build(const int *values, size_t n);
void segment_tree_destroy(SegmentTree *tree);
int segment_tree_update(SegmentTree *tree, size_t index, int value);
int segment_tree_query_max(const SegmentTree *tree, size_t left, size_t right);

#endif
