#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t;
    unsigned n, s, i, ans;
    int st, md, end;

    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        unsigned prefixSum[n], a[n];
        cin >> a[0];
        prefixSum[0] = a[0];
        for (i = 1; i < n; ++i)
        {
            cin >> a[i];
            prefixSum[i] = a[i] + prefixSum[i - 1];
        }

        if (prefixSum[n - 1] < s)
        {
            cout << -1 << endl;
            continue;
        }
        ans = INT32_MAX;
        st = 0;
        end = n - 1;
        while (st <= end)
        {
            md = (st + end) / 2;
            if (prefixSum[md] < s)
                st = md + 1;
            else if (prefixSum[md] > s)
                end = md - 1;
            else
            {
                ans = min(ans, n - (md + 1));
                st = md + 1;
            }
        }
        for (i = 0; i < n; i++)
        {
            if (a[i])
            {
                st = i + 1;
                end = n - 1;
                while (st <= end)
                {
                    md = (st + end) / 2;
                    if (prefixSum[md] - prefixSum[i] < s)
                        st = md + 1;
                    else if (prefixSum[md] - prefixSum[i] > s)
                        end = md - 1;
                    else
                    {
                        ans = min(ans, (n - (md + 1)) + i + 1);
                        st = md + 1;
                    }
                }
            }
        }
        cout << ans << endl;
    }
}