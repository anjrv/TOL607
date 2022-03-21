#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, p, n, a, b;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &c, &p);
        for (int j = 0; j < p; j++)
        {
            scanf("%d %d", &a, &b); // ???
        }

        printf("%d\n", c - 1);
    }

    return 0;
}