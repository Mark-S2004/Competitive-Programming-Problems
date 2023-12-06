#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n, i, m, q, st, md, end, ans;

    cin >> n;
    unsigned a[n];
    cin >> a[0];
    for (i = 1; i < n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    cin >> m;
    while (m--)
    {
        cin >> q;
        st = 0;
        end = n - 1;

        while (st <= end)
        {
            md = (st + end) / 2;
            if (q == a[md])
            {
                ans = md;
                break;
            }
            else if (q > a[md])
                st = md + 1;
            else
            {
                if (!md || q > a[md - 1])
                {
                    ans = md;
                    break;
                }
                else
                    end = md - 1;
            }
        }

        cout << ans + 1 << '\n';
    }
}