#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100010

typedef struct house
{
    int totalAge;
    int residents;
    int r;
} house;

house houses[SIZE];

void update(int idx, int age, int residents, int n)
{
    while (idx <= n)
    {
        houses[idx].totalAge += age;
        if (residents)
            houses[idx].residents += residents;

        idx += idx & -idx;
    }
}

void sum(int idx, int *s, int *r) {
    int sum = 0;
    int residents = 0;

    while (idx > 0) {
        sum += houses[idx].totalAge;
        residents += houses[idx].residents;

        idx -= idx & -idx;
    }

    *s = sum;
    *r = residents;
}

int main()
{
    int n = 0;
    int q = 0;

    scanf("%d %d", &n, &q);

    // Populate houses
    for (int i = 1; i <= n; i++)
    {
        int residents = 0;
        scanf(" %d", &residents);

        int age = 0;
        int houseAge = 0;
        for (int j = 0; j < residents; j++)
        {
            scanf(" %d", &age);
            houseAge += age;
        }

        update(i, houseAge, residents, n);
        houses[i].r = residents;
    }

    int a = 0;
    int b = 0;
    int query = 0;

    for (int i = 0; i < q; i++)
    {
        scanf(" %d", &query);
        switch (query)
        {
        case 1:
            scanf("%d %d", &a, &b);
            update(a, b, 1, n);
            houses[i].r++;
            break;
        case 2:
            scanf("%d", &a);
            for (int i = 1; i <= n; i++) {
                update(i, houses[i].r * a, 0, n);
            }

            break;
        case 3:
            scanf("%d %d", &a, &b);
            int aSum;
            int aRes;
            int bSum;
            int bRes;
            
            sum(a - 1, &aSum, &aRes);
            sum(b, &bSum, &bRes);

            double res = (bSum - aSum) / (double)(bRes - aRes);
            printf("%f\n", res);

            break;
        }
    }

    return 0;
}
