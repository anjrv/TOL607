#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(long long *)a - *(long long *)b);
}

int main()
{
    int systems = 0;
    long long ships = 0;

    scanf("%d", &systems);
    scanf("%lld", &ships);

    long long battles[systems];

    for (int i = 0; i < systems; i++)
    {
        scanf("%lld", &battles[i]);
    }

    qsort(battles, systems, sizeof(long long), cmp);

    int wins = 0;

    for (; wins < systems; wins++)
    {
        if (ships <= battles[wins])
            break;

        ships -= battles[wins];
    }

    printf("%d\n", wins);

    return 0;
}