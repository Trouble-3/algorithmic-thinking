#include <stdio.h>
#include <stdlib.h>
#include "hash_set.h"

int main(void) {
    size_t n;
    if (scanf("%zu", &n) != 1) return 1;
    HashSet *set = hash_set_create(n * 2 + 1);
    if (!set) return 1;
    int duplicate = 0;
    for (size_t i = 0; i < n; ++i) {
        int x;
        if (scanf("%d", &x) != 1) { hash_set_destroy(set); return 1; }
        if (hash_set_contains(set, x)) duplicate = 1;
        else if (hash_set_insert(set, x) == -1) { hash_set_destroy(set); return 1; }
    }
    printf("%s\n", duplicate ? "YES" : "NO");
    hash_set_destroy(set);
    return 0;
}
