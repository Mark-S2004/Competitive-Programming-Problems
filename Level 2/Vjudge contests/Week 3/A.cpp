#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

const int MOD = 1e9 + 7;

ull fastPow(ull a, ull b)
{
    if (b == 0)
        return 1;
    ull res = fastPow(a, b / 2);
    if (b % 2)
        return ((res * res) % MOD * a % MOD) % MOD;
    else
        return (res * res) % MOD;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i, aCount = 0;
    long long steps = 0, nextStep = 0;
    string ab;
    cin >> ab;
    n = int(ab.length());

    for (i = 0; i < n; ++i)
    {
        if (ab[i] == 'a')
        {
            nextStep += fastPow(2, aCount);
            nextStep %= MOD;
            ++aCount;
        }
        else
        {
            steps += nextStep;
            steps %= MOD;
        }
    }

    cout << steps % MOD;
}