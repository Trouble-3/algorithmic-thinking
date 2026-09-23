#include "binary_search.h"

int binary_search(const int *a, size_t n, int target) {
    size_t low = 0, high = n;
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        if (a[mid] == target) return (int)mid;
        if (a[mid] < target) low = mid + 1;
        else high = mid;
    }
    return -1;
}

size_t first_true(size_t low, size_t high, int (*predicate)(size_t, void *), void *ctx) {
    while (low < high) {
        size_t mid = low + (high - low) / 2;
        if (predicate(mid, ctx)) high = mid;
        else low = mid + 1;
    }
    return low;
}
