#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void toggle(int BIT[], int FLAG[], int idx, int n)
{
    int delta = 0;

    // Check if we need to decrement or increment sums
    if (FLAG[idx - 1]) {
        delta = -1;
        FLAG[idx - 1] = 0;
    } else {
        delta = 1;
        FLAG[idx - 1] = 1;
    }

    while (idx <= n)
    {
        BIT[idx] += delta;
        idx += idx & (-idx);
    }
}

int sum(int BIT[], int idx)
{
    int sum = 0;

    while (idx > 0)
    {
        sum += BIT[idx];
        idx -= idx & (-idx);
    }

    return sum;
}

int main()
{
    int n = 0;
    int k = 0;

    scanf("%d %d", &n, &k);

    int *sums = malloc(sizeof(int) * (n + 1));
    memset(sums, 0, sizeof(int) * (n + 1));

    int *bits = malloc(sizeof(int) * n);
    memset(bits, 0, sizeof(int) * n);

    int l = 0;
    int r = 0;
    char query = 'X';

    for (int i = 0; i < k; i++)
    {
        // Need the space delim otherwise whitespace crashes this
        scanf(" %c", &query);

        if (query == 'C')
        {
            scanf("%d %d", &l, &r);
            printf("%d\n", sum(sums, r) - sum(sums, l - 1));
        }
        else
        {
            scanf("%d", &l);
            toggle(sums, bits, l, n);
        }
    }

    free(sums);
    free(bits);

    return 0;
}
