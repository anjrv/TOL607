#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// At most 250 test cases
char grid[250][250];
char activities[250];
char ans[250];

// ASCII A = 65
// ASCII Z = 90
int main()
{
    int n;
    int iter = 0;

    // Loop read until line containing 0
    while (scanf("%d", &n) == 1 && n)
    {
        if (iter++)
        {
            memset(grid, 0, sizeof(grid));
            memset(activities, 0, sizeof(activities));
            memset(ans, 0, sizeof(ans));
            putchar('\n');
        }

        for (int i = 0; i < n; i++)
        {
            // Each line containing 5 activities
            for (int j = 0; j < 6; j++)
            {
                scanf(" %c", &activities[j]);
            }

            for (int j = 0; j < 6; j++)
            {
                grid[activities[5]][activities[j]] = 1;
                ans[activities[j]] = 1;
            }
        }

        // All uppercase letters
        for (int i = 65; i <= 90; i++)
        {
            for (int j = 65; j <= 90; j++)
            {
                for (int k = 65; k <= 90; k++)
                {
                    grid[j][k] = grid[j][k] | (grid[j][i] && grid[i][k]);
                }
            }
        }

        for (int i = 65; i <= 90; i++)
        {
            if (ans[i])
            {
                ans[i] = 0;
                printf("%c", i);

                for (int j = i + 1; j <= 90; j++)
                {
                    if (grid[i][j] && grid[j][i])
                    {
                        printf(" %c", j);
                        ans[j] = 0;
                    }
                }

                putchar('\n');
            }
        }
    }

    return 0;
}
