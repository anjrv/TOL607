#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN(X, Y) (((X) > (Y)) ? (Y) : (X))

int main()
{
    int n = 0;

    scanf("%d", &n);

    int coins[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }

    // the smallest counterexample is less
    // than the sum of the two largest denominations.
    int maxVal = coins[n - 1] << 1;
    unsigned long mem = maxVal * sizeof(int);

    int *dp = malloc(mem);
    memset(dp, 1, mem);
    dp[0] = 0;

    int *greedy = malloc(mem);
    memcpy(greedy, dp, mem);

    int isValid = 1;
    int loc = 0;

    for (int i = 1; i < maxVal; i++)
    {
        while (loc < n - 1 && i >= coins[loc + 1])
        {
            ++loc;
        }

        for (int j = 0; j < n && i >= coins[j]; j++)
        {
            dp[i] = MIN(dp[i], dp[i - coins[j]] + 1);
        }

        greedy[i] = greedy[i - coins[loc]] + 1;

        if (dp[i] != greedy[i])
        {
            isValid = 0;
            break;
        }
    }

    free(dp);
    free(greedy);

    if (isValid)
        printf("canonical\n");
    else
        printf("non-canonical\n");

    return 0;
}
