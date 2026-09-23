#include "dp.h"

#include <limits.h>
#include <stdlib.h>

static long long fib_rec(size_t n, long long *memo) {
    if (n < 2) return (long long)n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fib_rec(n - 1, memo) + fib_rec(n - 2, memo);
    return memo[n];
}

long long fibonacci_memo(size_t n) {
    if (n > 90) return -1;
    long long *memo = malloc((n + 1) * sizeof(*memo));
    if (!memo) return -1;
    for (size_t i = 0; i <= n; ++i) memo[i] = -1;
    long long result = fib_rec(n, memo);
    free(memo);
    return result;
}

int min_coins(const int *coins, size_t coin_count, int amount) {
    if (!coins || amount < 0) return -1;
    int *dp = malloc((size_t)(amount + 1) * sizeof(*dp));
    if (!dp) return -1;
    for (int i = 0; i <= amount; ++i) dp[i] = INT_MAX / 4;
    dp[0] = 0;

    for (int value = 1; value <= amount; ++value) {
        for (size_t j = 0; j < coin_count; ++j) {
            int coin = coins[j];
            if (coin > 0 && coin <= value && dp[value - coin] + 1 < dp[value])
                dp[value] = dp[value - coin] + 1;
        }
    }

    int result = dp[amount] >= INT_MAX / 4 ? -1 : dp[amount];
    free(dp);
    return result;
}
