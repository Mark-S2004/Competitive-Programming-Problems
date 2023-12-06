#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    unsigned n, i, ans = INT32_MAX;

    cin >> n;
    unsigned short c[n];
    for (i = 0; i < n; ++i)
        cin >> c[i];

    sort(c, c + n);
    for (i = 0; i < n; ++i)
        ans = min(ans, (unsigned)(n - ((upper_bound(c, c + n, c[i] * 2) - c - 1) - i + 1)));
    cout << ans;
}