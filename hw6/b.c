#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct conversation
{
    int idx;
    int size;
} conversation;

int owner(int i, conversation c[])
{
    while (c[i].idx != i)
    {
        c[i].idx = c[c[i].idx].idx;
        i = c[i].idx;
    }

    return i;
}

int merge(int i, int j, conversation c[])
{
    int idx1 = owner(i, c);
    int idx2 = owner(j, c);

    if (idx1 == idx2)
        return 0;

    if (c[idx1].size < c[idx2].size)
    {
        // Xor swap
        idx1 = idx1 ^ idx2;
        idx2 = idx1 ^ idx2;
        idx1 = idx1 ^ idx2;
    }

    c[idx2].idx = idx1;
    c[idx1].size += c[idx2].size;

    return 0;
}

int main()
{
    int n = 0;
    int q = 0;

    scanf("%d %d", &n, &q);

    conversation guests[n];

    // Guests start "solo", size 1 for i...n
    for (int i = 0; i < n; i++)
    {
        guests[i].idx = i;
        guests[i].size = 1;
    }

    int a = 0;
    int b = 0;
    char query = 'X';

    for (int i = 0; i < q; i++)
    {
        // Need the space delim otherwise whitespace crashes this
        scanf(" %c", &query);

        if (query == 't')
        {
            scanf("%d %d", &a, &b);
            merge(a - 1, b - 1, guests);
        }
        else
        {
            scanf("%d", &a);
            printf("%d\n", guests[owner(a - 1, guests)].size);
        }
    }

    return 0;
}
