#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toggle(int b[], int i)
{
    b[i >> 5] ^= (1 << (i & 0x1F));

    return 0;
}

// Naive loop count not fast enough
// Reevaluate - popcount, shift out bits?
int count(int b[], int l, int r)
{
    int count = 0;

    for (int i = l; i < r; i++)
    {
        if (b[i >> 5] & (1 << (i & 0x1F)))
            count++;
    }

    return count;
}

int main()
{
    int n = 0;
    int k = 0;

    scanf("%d %d", &n, &k);

    int *bits = malloc(sizeof(int) * (n / 32 + 1));
    memset(bits, 0, sizeof(int) * (n / 32 + 1));

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
            printf("%d\n", count(bits, l - 1, r));
        }
        else
        {
            scanf("%d", &l);
            toggle(bits, l - 1);
        }
    }

    return 0;
}
