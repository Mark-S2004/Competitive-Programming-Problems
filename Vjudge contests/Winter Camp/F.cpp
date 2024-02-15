#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, t, awakeTheroems = 0, i, maxTheroems = 0;

    cin >> n >> k;
    int a[n];
    cin >> a[0];
    for (i = 1; i < n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (i = 0; i <= n - k; ++i)
    {
        cin >> t;
        maxTheroems = max(maxTheroems, awakeTheroems + a[min(i + k - 1, n - 1)] - a[max(0, i - 1)]);
        if (t)
            awakeTheroems = a[i];
    }

    cout << maxTheroems;
}