#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(X, Y) (((X) > (Y)) ? (Y) : (X))

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    short n = 0;

    scanf("%hd", &n);

    int coins[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    qsort(coins, n, sizeof(int), cmp);

    // the smallest counterexample is less
    // than the sum of the two largest denominations.
    int maxVal = coins[n - 1] + coins[n - 1];

    int dp[maxVal];
    memset(dp, 1, sizeof(dp));
    dp[0] = 0;

    int greedy[maxVal];
    memset(greedy, 1, sizeof(greedy));
    greedy[0] = 0;

    short isValid = 1;

    for (int i = 0; i < maxVal; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - coins[j] >= 0)
            {
                dp[i] = MIN(dp[i], dp[i - coins[j]] + 1);
                greedy[i] = greedy[i - coins[j]] + 1;
            }
        }

        if (dp[i] != greedy[i]) {
            isValid = 0;
            break;
        }
    }

    if (isValid)
        printf("canonical\n");
    else
        printf("non-canonical\n");


    return 0;
}
