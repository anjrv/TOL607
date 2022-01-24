#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n = 0;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &nums[i]);
    }

    qsort(nums, n, sizeof(int), cmp);

    long long res = 0;

    for (int i = 1; i < n; i++) {
        long long val = (nums[i] - nums[i - 1]);
        res += (val * val);
    }

    printf("%lld\n", res);

    return 0;
}