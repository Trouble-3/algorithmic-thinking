#include <stdio.h>
#include <stdlib.h>
#include "union_find.h"

int main(void) {
    size_t n, q;
    if (scanf("%zu %zu", &n, &q) != 2) return 1;
    UnionFind *uf = union_find_create(n);
    if (!uf) return 1;
    for (size_t i = 0; i < q; ++i) {
        char op; size_t a, b;
        if (scanf(" %c %zu %zu", &op, &a, &b) != 3) { union_find_destroy(uf); return 1; }
        if (op == 'U') {
            if (union_find_union(uf, a, b) < 0) { union_find_destroy(uf); return 1; }
        } else if (op == 'Q') {
            int connected = union_find_connected(uf, a, b);
            printf("%s\n", connected ? "YES" : "NO");
        } else { union_find_destroy(uf); return 1; }
    }
    union_find_destroy(uf);
    return 0;
}
