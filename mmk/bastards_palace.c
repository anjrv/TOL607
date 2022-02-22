#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// NOTE: Fails test case 3

typedef struct floor
{
    long long *opps;
    long long *strengths;
    int loc;
    int cnt;
    int floorDone;
} floor;

int main()
{
    int n, opps;
    unsigned long long s;

    scanf("%d %llu", &n, &s);

    floor *floors = malloc(sizeof(floor) * n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &opps);

        floors[i].opps = malloc(sizeof(long long) * opps);
        floors[i].strengths = malloc(sizeof(long long) * opps);
        floors[i].loc = 0;
        floors[i].cnt = opps;
        floors[i].floorDone = 0;

        for (int j = 0; j < opps; j++)
        {
            scanf("%lld", &floors[i].opps[j]);
        }

        for (int j = 0; j < opps; j++)
        {
            scanf("%lld", &floors[i].strengths[j]);
        }
    }

    int couldNot = 0;
    int isDone = 0;
    while (isDone < n && !couldNot)
    {
        couldNot = 1;

        for (int i = 0; i < n; i++)
        {
            if (floors[i].floorDone) continue;

            if (floors[i].loc == floors[i].cnt && !floors[i].floorDone)
            {
                isDone++;
                floors[i].floorDone = 1;
            }
            else
            {
                while (floors[i].opps[floors[i].loc] < s && floors[i].loc < floors[i].cnt)
                {
                    couldNot = 0;
                    s += floors[i].strengths[floors[i].loc++];
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        free(floors[i].opps);
        free(floors[i].strengths);
    }

    free(floors);

    if (isDone != n)
    {
        printf("%llu\n", s);
    }
    else
    {
        printf("Sigur!\n");
    }

    return 0;
}
