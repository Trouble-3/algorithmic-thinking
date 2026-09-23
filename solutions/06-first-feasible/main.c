#include <stdio.h>
#include <stddef.h>
#include "binary_search.h"

typedef struct { size_t threshold; } Context;

static int feasible(size_t x, void *ctx) {
    return x >= ((Context *)ctx)->threshold;
}

int main(void) {
    size_t low, high, threshold;
    if (scanf("%zu %zu %zu", &low, &high, &threshold) != 3) return 1;
    Context ctx = { threshold };
    size_t answer = first_true(low, high, feasible, &ctx);
    printf("%zu\n", answer);
    return 0;
}
