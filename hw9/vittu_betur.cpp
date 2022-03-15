#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lim = 1000001;
vector<int> primes;
vector<int> p(lim);
vector<int> h(lim);

void sieve()
{
    vector<bool> isPrime(lim, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= lim; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= lim; j += i)
                isPrime[j] = false;
        }
    }

    for (int i = 0; i < lim; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}

int factors(int n)
{
    int sqLim = (int)sqrt(n) + 1;

    for (auto prime : primes)
    {
        if (prime > sqLim)
            break;

        if (n % prime == 0)
            return p[n / prime] + p[prime];
    }

    return 1;
}

int main()
{
    sieve();

    p[2] = 1;
    h[2] = 1;

    for (int i = 3; i < lim; i++)
    {
        p[i] = factors(i);
        h[i] = p[i] + h[i - 1];
    }

    int n;

    while (cin >> n)
    {
        cout << h[n] << endl;
    }

    return 0;
}
