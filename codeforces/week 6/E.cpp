#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n, i, m;
    long long int t;

    cin >> n;
    long long int a[n];
    cin >> a[0];
    for (i = 1; i < n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    cin >> m;
    while (m--)
    {
        cin >> t;
        int st = 0, md, end = n - 1, ans;

        while (st <= end)
        {
            md = (st + end) / 2;
            if (a[md] < t)
                st = md + 1;
            else if (a[md] > t)
            {
                ans = md;
                end = md - 1;
            }
            else
            {
                ans = md;
                break;
            }
        }
        cout << a[ans] << ' ' << ans + 1 << endl;
    }
}