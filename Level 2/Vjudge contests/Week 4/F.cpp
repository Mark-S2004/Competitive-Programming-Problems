#include <bits/stdc++.h>
using namespace std;

#define SET_BITS_COUNT(x) __builtin_popcount(x)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, m, k, i, friends = 0;

    cin >> n >> m >> k;
    int armys[m], fedorArmy;
    for (i = 0; i < m; ++i)
        cin >> armys[i];
    cin >> fedorArmy;
    for (int army : armys)
        if (SET_BITS_COUNT(fedorArmy ^ army) <= k)
            ++friends;

    cout << friends;
}