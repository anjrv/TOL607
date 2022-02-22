#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int x1, x2, y1, y2, n, hitX, hitY;

    scanf("%d %d %d %d", &x1, &x2, &y1, &y2);
    scanf("%d", &n);

    int hits = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &hitX, &hitY);

        if (hitX <= x2 && hitX >= x1 && hitY <= y2 && hitY >= y1) {
            hits++;
        }
    }

    printf("%d\n", hits);

    return 0;
}

