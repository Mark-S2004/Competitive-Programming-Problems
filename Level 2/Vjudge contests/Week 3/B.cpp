#include <bits/stdc++.h>
using namespace std;

long long fastpow(long long a, long long b, long long m)
{
    if (b == 0)
        return 1;
    long long result = fastpow(a, b / 2, m);

    if (b % 2)
        return ((result * result) % m * a % m) % m;
    return (result * result) % m;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short p, i, j, primitiveRootsCount = 0;
    cin >> p;

    for (i = 1; i < p; ++i)
        for (j = 1; j < p; ++j)
        {
            if (j == p - 1)
            {
                if (!(fastpow(i, j, p)) - 1)
                    ++primitiveRootsCount;
            }
            else if (!(fastpow(i, j, p) - 1))
                break;
        }

    cout << primitiveRootsCount;
}