#include <iostream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double cross(pair<double, double> P, pair<double, double> Q, pair<double, double> R)
{
    return (Q.first - P.first) * (R.second - P.second) - (R.first - P.first) * (Q.second - P.second);
}

double distance(pair<double, double> P, pair<double, double> Q)
{

    return (P.first - Q.first) * (P.first - Q.first) + (P.second - Q.second) * (P.second - Q.second);
}

int main()
{
    vector<pair<double, double>> points, upper, lower;
    int n;
    double x, y;
    int i = 0;

    cin >> n;
        
    for (i = 0; i < n; i++) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    int j = 0;
    int k = 0;
    sort(points.begin(), points.end());

    // Construct convex hull
    lower.resize(2 * n);
    upper.resize(2 * n);
    for (i = 0; i < n; i++)
    {
        while (j >= 2 && cross(lower[j - 2], lower[j - 1], points[i]) <= 0)
            j--;
        while (k >= 2 && cross(upper[k - 2], upper[k - 1], points[i]) >= 0)
            k--;
        lower[j++] = points[i];
        upper[k++] = points[i];
    }

    upper.resize(k);
    lower.resize(j);

    double maxDist = 0;
    i = 0;
    j--;
    int m = k - 1;

    while (i < m || j > 0)
    {
        maxDist = max(maxDist, distance(upper[i], lower[j]));
        if (i == m)
            j--;
        else if (j == 0)
            i++;
        else
        {
            if ((upper[i + 1].second - upper[i].second) * (lower[j].first - lower[j - 1].first) > (lower[j].second - lower[j - 1].second) * (upper[i + 1].first - upper[i].first))
                i++;
            else
                j--;
        }
    }

    cout << setprecision(15) << sqrt(maxDist) << endl;
}