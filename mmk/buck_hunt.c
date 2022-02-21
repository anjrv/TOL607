#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x1 = 0;
    int x2 = 0;
    int y1 = 0;
    int y2 = 0;

    scanf("%d %d %d %d", &x1, &x2, &y1, &y2);

    int n = 0;

    scanf("%d", &n);

    int hits = 0;

    int hitX = 0;
    int hitY = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hitX, &hitY);

        if (hitX <= x2 && hitX >= x1 && hitY <= y2 && hitY >= y1) {
            hits++;
        }
    }

    printf("%d\n", hits);

    return 0;
}

