#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dp.h"

int main(void) {
    size_t n;
    int amount;
    if (scanf("%zu %d", &n, &amount) != 2) return 1;
    int *coins = malloc(n * sizeof(*coins));
    if (!coins) return 1;
    for (size_t i = 0; i < n; ++i) if (scanf("%d", &coins[i]) != 1) { free(coins); return 1; }
    int answer = min_coins(coins, n, amount);
    printf("%d\n", answer);
    free(coins);
    return 0;
}
