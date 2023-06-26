#include <stdio.h>

#define MAX_AMOUNT 100000

long long makeChange(int amount, int coins[], int numCoins) {
    long long dp[MAX_AMOUNT + 1] = {0};
    dp[0] = 1;

    for (int i = 0; i < numCoins; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            dp[j] += dp[j - coins[i]];
        }
    }

    return dp[amount];
}

int main() {
    double amount;
    int coins[] = {10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5};
    int numCoins = sizeof(coins) / sizeof(coins[0]);

    printf("Enter the amount: ");
    scanf("%lf", &amount);

    while (amount != 0.00) {
        int cents = (int)(amount * 100);
        long long ways = makeChange(cents, coins, numCoins);
        printf("%6.2f %17lld\n", amount, ways);

        printf("Enter the amount: ");
        scanf("%lf", &amount);
    }

    return 0;
}
