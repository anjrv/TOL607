#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;

    while (scanf("%d", &n) == 1 && n != -1)
    {
        int *grid = malloc(sizeof(int) * n * n);

        for (int i = 0; i < n; i++)
        {
            int idx = i * n;
            for (int j = 0; j < n; j++)
            {
                scanf(" %d", &grid[idx + j]);
            }
        }

        for (int i = 0; i < n; i++)
        {
            int weak = 1;

            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    if (i != j && i != k && j != k)
                    {
                        // Check adjacents
                        if (grid[i * n + k] == 1 && grid[i * n + j] == 1 && grid[j * n + k] == 1)
                            weak = 0;
                    }
                }
            }
            if (weak)
            {
                printf("%d ", i);
            }
        }

        putchar('\n');
        free(grid);
    }

    return 0;
}
