#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    long long n = 0;
    scanf("%lld", &n);

    double x = log(n);
    double xi = n;

    while (fabsf(xi - x) >= 0.000001)
    {   x = xi;
        double fx = x * log(x) - log(n);
        double dx = log(x) + 1;
        xi = x - fx / dx;
    }

    printf("%f\n", x);

    return 0;
}