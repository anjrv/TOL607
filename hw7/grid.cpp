#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, m;
    char num;
    cin >> n >> m;

    int *grid = (int *)malloc(sizeof(int) * n * m);
    int *dist = (int *)malloc(sizeof(int) * n * m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            // Each digit is between 0 and 9, inclusive.
            // Should be able to use - '0' to convert
            grid[i * m + j] = num - '0';
            dist[i * m + j] = -1;
        }
    }

    dist[0] = 0;
    int dcol[] = {0, 0, 1, -1};
    int drow[] = {1, -1, 0, 0};

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();

        if (row == n - 1 && col == m - 1)
            break;

        for (int i = 0; i < 4; i++)
        {
            int curr = grid[row * m + col];
            int nextRow = row + drow[i] * curr;
            int nextCol = col + dcol[i] * curr;

            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m || dist[nextRow * m + nextCol] != -1)
                continue;

            dist[nextRow * m + nextCol] = dist[row * m + col] + 1;
            q.push({nextRow, nextCol});
        }
    }

    cout << dist[(n - 1) * m + m - 1] << endl;
    free(grid);
    free(dist);

    return 0;
}