#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<string, long long> ships;
    string name, recShip;
    int n, m, s;
    long long h;
    int mod = 1000000007;
    
    cin >> n;
    cin >> m;

    for (int i = 0; i < n; i++) {
        cin >> name;
        cin >> h;
        cin >> s;

        for (int j = 0; j < s; j++) {
            cin >> recShip;
            h += ships[recShip];
        }

        ships[name] = fmod(h, mod);
    }

    unsigned long long res = 0;
    for (int i = 0; i < m; i++) {
        cin >> name;
        cin >> s;

        res += ships[name] * s;
    }

    res = fmod(res, mod);
    cout << res << endl;

    return 0;
}