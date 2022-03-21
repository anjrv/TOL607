#include <stdio.h>
#include <stdlib.h>
#include <tgmath.h>

int main()
{
     long long n;
     scanf("%lld", &n);

     for (int i = 128; i >= 0; i--)
    {
         long long curr = (long long)powl(i, 9);

        if (curr > n)
            continue;

        if (n % curr == 0)
        {
            printf("%d\n", i);
            return 0;
        }
    }

    printf("%d\n", 1);
    return 0;
}
