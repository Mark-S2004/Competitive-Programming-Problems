using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m, train, i, st, md, end, crash;

    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        crash = 0;
        int trains[n];
        for (i = 0; i < n; ++i)
        {
            cin >> trains[i];
        }
        for (i = 0; i < m; ++i)
        {
            cin >> train;
            st = 0;
            end = n - 1;
            while (st <= end)
            {
                md = (st + end) / 2;
                if (trains[md] == train)
                {
                    ++crash;
                    break;
                }
                if (train > trains[md])
                    st = md + 1;
                else
                    end = md - 1;
            }
        }

        cout << crash << endl;
    }
}