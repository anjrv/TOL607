#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int h, v;

    scanf("%d %d", &h, &v);

    printf("%d\n", (int) ceil(h / sin(v * (M_PI / 180.0))));
    return 0;
}
