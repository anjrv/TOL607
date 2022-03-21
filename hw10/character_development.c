#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    // For n there are 2^n subsets which contain n single element sets and the empty set
    printf("%d\n", (1 << n) - n - 1);
    
    return 0;
}
