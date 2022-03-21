#include <stdio.h>
#include <stdlib.h>

int MOD = 1000000007;

int main()
{
    int n;
    scanf("%d", &n);
    int ones = 0;
    int twos = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int curr;
        scanf("%d", &curr);

        if (curr == 1)
            ones++;
        else if (curr == 2) {
            twos = 2 * twos + ones;
            twos %= MOD;
        } else {
            ans += twos;
            ans %= MOD;
        }
    }

    printf("%d\n", ans);

    return 0;
}