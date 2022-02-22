#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[1000001];
    scanf("%s", input);
    int len = strlen(input);

    char *res = malloc(len + 1); // At most no deletions
    int n = 0;

    for (int i = 0; i <= len; i++)
    {
        char curr = input[i];

        if (curr == '<' && n > 0)
        {
            n--;
        }
        else
        {
            res[n++] = curr;
        }
    }

    if (n > 0)
        printf("%s\n", res);

    free(res);

    return 0;
}
