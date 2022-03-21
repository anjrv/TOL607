#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int n;

    while (scanf("%d", &n) == 1)
    {
        int sum = 1;
        int lim = (int)sqrt(n) + 1;

        for (int i = 2; i < lim; i++)
        {
            if (n % i == 0)
            {
                sum += i;

                int tmp = n / i;
                if (i != tmp)
                    sum += tmp;
            }
        }

        if (sum == n)
            printf("%d perfect\n", n);
        else if (abs(sum - n) <= 2)
            printf("%d almost perfect\n", n);
        else
            printf("%d not perfect\n", n);
    }

    return 0;
}
