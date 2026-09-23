#include <stdio.h>
#include <stdlib.h>
#include "segment_tree.h"

int main(void) {
    size_t n, q;
    if (scanf("%zu %zu", &n, &q) != 2 || n == 0) return 1;
    int *a = malloc(n * sizeof(*a));
    if (!a) return 1;
    for (size_t i = 0; i < n; ++i) if (scanf("%d", &a[i]) != 1) { free(a); return 1; }
    SegmentTree *tree = segment_tree_build(a, n);
    free(a);
    if (!tree) return 1;
    for (size_t i = 0; i < q; ++i) {
        char op; size_t x, y; int value;
        if (scanf(" %c", &op) != 1) { segment_tree_destroy(tree); return 1; }
        if (op == 'Q') {
            if (scanf("%zu %zu", &x, &y) != 2) { segment_tree_destroy(tree); return 1; }
            printf("%d\n", segment_tree_query_max(tree, x, y));
        } else if (op == 'U') {
            if (scanf("%zu %d", &x, &value) != 2 || segment_tree_update(tree, x, value) == 0) { segment_tree_destroy(tree); return 1; }
        } else { segment_tree_destroy(tree); return 1; }
    }
    segment_tree_destroy(tree);
    return 0;
}
