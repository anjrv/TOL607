#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int main()
{
    int capacity, n;

    while (scanf("%d %d", &capacity, &n) == 2)
    {
        int values[n];
        int weights[n];

        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &values[i], &weights[i]);
        }

        int dp[n + 1][capacity + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= capacity; j++)
            {
                if (weights[i - 1] <= j)
                {
                    dp[i][j] = MAX(dp[i - 1][j], values[i - 1] + dp[i - 1][j - weights[i - 1]]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        int idx = 0;
        int curr = capacity;
        int indices[capacity];

        // Walk backwards to find choices
        for (int i = n; i > 0; i--)
        {
            if (dp[i][curr] != dp[i - 1][curr])
            {
                indices[idx] = i - 1;
                curr -= weights[i - 1];
                idx++;
            }
        }

        printf("%d\n", idx);

        for (int i = 0; i < idx; i++)
        {
            if (i)
                putchar(' ');
            printf("%d", indices[i]);
        }

        putchar('\n');
    }

    return 0;
}
