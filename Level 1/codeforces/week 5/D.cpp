#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, x, y, z;
    long long int ans = 0;

    cin >> n;
    unsigned short a[n];
    for (x = 0; x < n; ++x)
    {
        cin >> a[x];
    }

    for (x = 0; x < n; ++x)
    {
        for (y = 0; y < n; ++y)
        {
            for (z = 0; z < n; z++)
            {
                if (a[x] * a[y] == a[z])
                    ++ans;
            }
        }
    }

    cout << ans;
}