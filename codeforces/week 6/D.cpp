#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n, x, i, st = 1, md, end, gold;
    int ans = -1;

    cin >> n >> x;
    end = n;
    unsigned a[n];
    cin >> a[0];
    for (i = 1; i < n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    while (st <= end)
    {
        md = (st + end) / 2;
        for (i = md - 1; i < n; ++i)
        {
            gold = a[i];
            if (i > md - 1)
                gold -= a[i - md];
            if (gold >= x)
            {
                ans = md;
                end = md - 1;
                break;
            }
        }
        if (gold < x)
            st = md + 1;
    }
    cout << ans;
}