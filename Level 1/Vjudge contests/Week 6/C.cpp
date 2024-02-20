#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n, m, i;
    int st = 0, md, end;

    cin >> n >> m;
    long long int a[n], b;
    cin >> a[0];
    for (i = 1; i < n; ++i)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }

    while (m--)
    {
        cin >> b;
        end = n - 1;
        while (st <= end)
        {
            md = (st + end) / 2;
            if (a[md] == b)
            {
                break;
            }
            else if (a[md] < b)
                st = md + 1;
            else
            {
                if (md)
                {
                    if (a[md - 1] < b)
                        break;
                }
                end = md - 1;
            }
        }
        cout << md + 1 << ' ' << (md ? (b - a[md - 1]) : b) << endl;
    }
}