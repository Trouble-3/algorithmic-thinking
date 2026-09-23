#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stddef.h>

int binary_search(const int *a, size_t n, int target);
size_t first_true(size_t low, size_t high, int (*predicate)(size_t, void *), void *ctx);

#endif
