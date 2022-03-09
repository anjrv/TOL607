#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <string.h>

using namespace std;

unsigned long long intersects[512];
unsigned long long roads[512][512];
vector<int> dists[512];

int main()
{
    // Assign high values
    memset(intersects, 1, sizeof(intersects));
    memset(roads, 1, sizeof(roads));
    roads[0][0] = 0;

    // n represents the number of intersections in the city,
    // m represents the number of roads in the city,
    // t is the number of repair stations,
    // d is the distance that you can bike (starting with a fully inflated tire) before your tire goes flat again.
    // The intersections are numbered from 1 to n. Your school is at intersection 1 and your home is at intersection n.
    int n, m, t, d, u, v, w;
    cin >> n >> m >> t >> d;

    // Repair stations
    int sSize = t + 2;
    int *stations = (int *)malloc(sizeof(int) * sSize);
    for (int i = 0; i < t; i++)
    {
        cin >> stations[i];
    }

    stations[t] = 1;
    stations[t + 1] = n;

    // Roads (preallocated array)
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        roads[u][v] = roads[v][u] = w;
    }

    // Floyd
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                roads[j][k] = min(roads[j][k], roads[j][i] + roads[i][k]);
            }
        }
    }

    // Map valid adjacency
    for (int i = 0; i < sSize; i++)
    {
        for (int j = i + 1; j < sSize; j++)
        {
            if (roads[stations[i]][stations[j]] > d)
                continue;

            dists[stations[i]].push_back(stations[j]);
            dists[stations[j]].push_back(stations[i]);
        }
    }

    // Dijkstra
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    vector<bool> station(512, false);

    pq.emplace(0, 1);
    intersects[0] = 0;
    intersects[1] = 0;

    while (!pq.empty())
    {
        int i = pq.top().second;
        pq.pop();

        if (station[i])
            continue; // Visited
        station[i] = true;

        for (auto j : dists[i])
        {
            unsigned long long k = roads[i][j];
            if (!station[j] && intersects[j] > intersects[i] + k)
            {
                intersects[j] = intersects[i] + k;
                pq.emplace(intersects[j], j);
            }
        }
    }

    // unsigned long long memset value
    if (intersects[n] == 72340172838076673)
        cout << "stuck" << endl;
    else
        cout << intersects[n] << endl;

    free(stations);

    return 0;
}
