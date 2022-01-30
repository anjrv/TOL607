#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0;
    scanf("%d", &n);

    char str[n];
    scanf("%s", &str);

    int cnt = 0;
    int isA = 1;

    for (int i = n - 1; i >= 1; i--) {
        if (isA) {
            if (str[i] == 'A') {
                continue;
            } else {
                if (str[i - 1] == 'B') {
                    isA = 0;
                }

                cnt++;
            }
        } else {
            if (str[i] == 'B') {
                continue;
            } else {
                if (str[i - 1] == 'A') {
                    isA = 1;
                }

                cnt++;
            }

        }
    }

    if ((isA && str[0] == 'B') || (!isA && str[0] == 'A')) cnt++;

    printf("%d\n", cnt);

    return 0;
}