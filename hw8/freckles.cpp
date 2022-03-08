#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct
{
    int start;
    int end;
    long double distSq;
} edge;

bool cmp(edge start, edge end)
{
    return start.distSq < end.distSq;
}

int tc, n;

vector<pair<long double, long double>> freckles;
vector<edge> edges;
vector<int> mins;

int find(int idx)
{
    if (mins[idx] == -1)
        return idx;

    mins[idx] = find(mins[idx]);
    return mins[idx];
}

int join(int start, int end)
{
    start = find(start);
    end = find(end);

    if (start == end)
    {
        return -1; // Nothing done
    }

    mins[start] = end;
    return 0;
}

int main()
{
    cout << fixed << setprecision(2);

    cin >> tc;
    int iter = 0;

    for (int i = 0; i < tc; i++)
    {
        if (iter++)
        {
            cout << endl;
            edges.clear();
        }

        cin >> n;
        freckles.resize(n);
        for (int j = 0; j < n; j++)
        {
            cin >> freckles[j].first >> freckles[j].second;
        }

        for (int j = 0; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                long double d = pow(freckles[j].first - freckles[k].first, 2) + pow(freckles[j].second - freckles[k].second, 2);
                edges.push_back({j, k, d});
            }
        }

        sort(edges.begin(), edges.end(), cmp);

        long double dist = 0;
        mins.assign(n, -1);

        for (auto curr : edges)
        {
            if (find(curr.start) != find(curr.end))
            {
                dist += sqrt(curr.distSq);
                join(curr.start, curr.end);
            }
        }

        cout << dist << endl;
    }

    return 0;
}
