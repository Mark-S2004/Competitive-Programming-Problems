#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short t;
    int n, k, dessert;
    ll i, cost, ways, lastBit;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        ways = 0;
        lastBit = min(k, __lg(n) + 1);

        for (i = 0; i < (1LL << lastBit); ++i)
        {
            cost = 0;
            for (dessert = 0; dessert < lastBit; ++dessert)
                if (i & (1LL << dessert))
                    cost += (1LL << dessert);
            if (cost <= n)
                ++ways;
        }

        cout << ways << '\n';
    }
}