#include <stdio.h>
#include <stdlib.h>

int grid[1001][1001];
int dcol[] = {0, 0, 1, -1};
int drow[] = {1, -1, 0, 0};

int helper(int n, int m, int row, int col, int bc, int dc)
{
    int curr = grid[row][col];

    if (curr == 1)
    {
        grid[row][col] = dc;
    }
    else if (!curr)
    {
        grid[row][col] = bc;
    }
    else
    {
        return 0;
    }

    for (int i = 0; i < 4; i++)
    {
        int nextRow = row + drow[i];
        int nextCol = col + dcol[i];
        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m || grid[nextRow][nextCol] != curr)
            continue;
        helper(n, m, nextRow, nextCol, bc, dc);
    }

    return 0;
}

int main()
{
    int bc = -1;
    int dc = 2;

    int row, col, queries, r1, r2, c1, c2;
    scanf("%d %d", &row, &col);

    char *s = malloc(col + 1);

    for (int i = 0; i < row; i++)
    {
        scanf("%s", s);

        for (int j = 0; j < col; j++)
        {
            grid[i][j] = s[j] - '0';
        }
    }

    free(s);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (!grid[i][j])
                helper(row, col, i, j, bc--, dc);
            else if (grid[i][j] == 1)
                helper(row, col, i, j, bc, dc++);
        }
    }

    scanf("%d", &queries);

    for (int i = 0; i < queries; i++)
    {
        scanf(" %d %d %d %d", &r1, &c1, &r2, &c2);

        if (grid[r1 - 1][c1 - 1] != grid[r2 - 1][c2 - 1])
            printf("neither\n");
        else if (grid[r1 - 1][c1 - 1] > 1)
            printf("decimal\n");
        else if (grid[r1 - 1][c1 - 1] < 0)
            printf("binary\n");
    }

    return 0;
}