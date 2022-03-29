#include <iostream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

double cross(pair<double, double> P, pair<double, double> Q, pair<double, double> R)
{
    return (Q.first - P.first) * (R.second - P.second) - (R.first - P.first) * (Q.second - P.second);
}

double distance(pair<double, double> P, pair<double, double> Q)
{

    return sqrt((P.first - Q.first) * (P.first - Q.first) + (P.second - Q.second) * (P.second - Q.second));
}

int main()
{
    string turn;

    while (getline(cin, turn))
    {
        stringstream sin(turn);
        double x, y;
        int i = 0;
        int n = 0;
        vector<pair<double, double>> points, upper, lower;

        while (sin >> x >> y)
        {
            points.push_back({x, y});
            n++;
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

        double dist = 0;

        for (i = 1; i < k; i++)
        {
            dist += distance(upper[i - 1], upper[i]);
        }

        for (i = 1; i < j; i++)
        {
            dist += distance(lower[i - 1], lower[i]);
        }

        cout << setprecision(15) << 100 * (n / (1 + dist)) << endl;
    }
}