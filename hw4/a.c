#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

int main()
{
    int n = 0;
    int k = 0;
    scanf("%d", &n);
    scanf("%d", &k);

    int* s = malloc(n * sizeof(int));

    int p[n];
    int m[n][k];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &s[i]);

        p[i] = i > 0 ? p[i - 1] + s[i] : s[i];
        m[i][0] = p[i];
    }

    for (int i = 0; i < k; i++) {
        m[0][i] = s[0];
    }

    free(s);

    for (int i = 1; i < n; i++) {
        int len = i != n - 1 ? k - 1 : k;

        for (int j = 1; j < len; j++) {
            m[i][j] = INT_MAX;

            for (int h = 0; h < i; h++) {
                int curr = MAX(m[h][j - 1], p[i] - p[h]);

                if (m[i][j] > curr) {
                    m[i][j] = curr;
                }
            }
        }
    }

    printf("%d\n", m[n - 1][k - 1]);

    return 0;
}