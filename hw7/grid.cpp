#include <stdlib.h>
#include <iostream>
#include <queue>

using namespace std;

int dcol[] = {0, 0, 1, -1};
int drow[] = {1, -1, 0, 0};

int main()
{
    int n, m;
    char num;
    cin >> n >> m;

    int *grid = (int *)malloc(sizeof(int) * n * m);
    int *dist = (int *)malloc(sizeof(int) * n * m);

    for (int i = 0; i < n; i++)
    {
        int idx = i * m;
        for (int j = 0; j < m; j++)
        {
            cin >> num;
            // Each digit is between 0 and 9, inclusive.
            // Should be able to use - '0' to convert
            int idxJ = idx + j;
            grid[idxJ] = num - '0';
            dist[idxJ] = -1;
        }
    }

    dist[0] = 0;

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
            int idx1 = row * m + col;
            int curr = grid[idx1];

            int nextRow = row + drow[i] * curr;
            int nextCol = col + dcol[i] * curr;
            int idx2 = nextRow * m + nextCol;

            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m || dist[idx2] != -1)
                continue;

            dist[idx2] = dist[idx1] + 1;
            q.push({nextRow, nextCol});
        }
    }

    cout << dist[(n - 1) * m + m - 1] << endl;

    free(grid);
    free(dist);

    return 0;
}