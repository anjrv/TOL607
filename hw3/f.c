#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;

    scanf("%d", &n);

    long long nums[n];

    int longestStart = 0;
    int longestEnd = 0;
    int longestCount = 0;

    int currStart = 0;
    int currEnd = 0;
    long long currNum = -1;
    int currCount = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &nums[i]);

        if (nums[i] != currNum)
        {
            if (currCount > longestCount)
            {
                currEnd = i - 1;

                longestStart = currStart;
                longestEnd = currEnd;
                longestCount = currCount;
            }

            currNum = nums[i];
            currStart = i;
            currCount = 1;
        }
        else
        {
            currCount++;
        }
    }

    // Sequence ended at last number
    if (currCount > longestCount)
    {
        longestStart = currStart;
        longestEnd = n - 1;
        longestCount = currCount;
    }

    printf("%d %d\n", longestStart, longestEnd);

    return 0;
}