#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, pair<int, int>> pipii_t;

int main()
{
    priority_queue<pipii_t, vector<pipii_t>, greater<pipii_t>> prio;
    vector<vector<pair<int, int>>> adjacents;
    vector<pair<int, int>> tree;
    vector<bool> taken;

    int n, m, u, v, w;

    int iter = 0;
    while (1)
    {
        cin >> n >> m;

        if (!n && !m)
            break;

        if (!m)
        {
            cout << "Impossible" << endl;
            continue;
        }

        if (iter++)
        {
            if (!prio.empty())
                prio = priority_queue<pipii_t, vector<pipii_t>, greater<pipii_t>>();

            tree.clear();
        }

        adjacents.assign(n, vector<pair<int, int>>());
        taken.assign(n, false);

        for (int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            adjacents[u].push_back({v, w});
            adjacents[v].push_back({u, w});
        }

        for (auto curr : adjacents[0])
            prio.push(pipii_t(curr.second, {0, curr.first}));

        taken[0] = true;
        long long cost = 0;

        // Something like Prim
        while (!prio.empty())
        {
            int c = prio.top().first;
            pair<int, int> edge = prio.top().second;
            prio.pop();

            if (!taken[edge.second])
            {
                taken[edge.second] = true;
                cost += c;
                tree.push_back({min(edge.first, edge.second), max(edge.first, edge.second)});
                for (auto curr : adjacents[edge.second])
                {
                    if (!taken[curr.first])
                        prio.push(pipii_t(curr.second, {edge.second, curr.first}));
                }
            }
        }

        if (tree.size() < n - 1)
            cout << "Impossible" << endl;
        else
        {
            sort(tree.begin(), tree.end());
            cout << cost << endl;
            for (int i = 0; i < n - 1; i++)
            {
                cout << tree[i].first << ' ' << tree[i].second << '\n'; // Endl makes first test case fail??
            }
        }
    }

    return 0;
}