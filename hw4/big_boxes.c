#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MIN(X, Y) (((X) > (Y)) ? (Y) : (X))

int subSum(int s[], int n, int k)
{
    int sum = 0;
    int res = 1;

    for (int i = 0; i < n; i ++) {
        int x = s[i];
        sum += x;
        if (sum > k) {
            sum = x;
            res++;
        }
    }

    return res;
}

int main()
{
    int n = 0;
    int k = 0;
    scanf("%d", &n);
    scanf("%d", &k);

    // int *s = malloc(n * sizeof(int));
    int s[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);
    }

    int left = 0;
    int right = 0;

    for (int i = 0; i < n; i ++) {
        left = MAX(left, s[i]);
        right += s[i];
    }

    int res = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (subSum(s, n, mid) <= k) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    printf("%d\n", res);

    return 0;
}