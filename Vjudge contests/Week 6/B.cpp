#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t;
    unsigned n, q, i, x, a;

    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        unsigned prefixSum[n];
        priority_queue<unsigned> sugar;
        for (i = 0; i < n; ++i)
        {
            cin >> a;
            sugar.push(a);
        }
        prefixSum[0] = sugar.top();
        sugar.pop();
        for (i = 1; i < n; ++i)
        {
            prefixSum[i] = sugar.top() + prefixSum[i - 1];
            sugar.pop();
        }

        while (q--)
        {
            cin >> x;
            int st = 0, md, end = n - 1, ans = -1;

            while (st <= end)
            {
                md = (st + end) / 2;
                if (prefixSum[md] < x)
                    st = md + 1;
                else if (prefixSum[md] > x)
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
            if (ans != -1)
                ++ans;
            cout << ans << endl;
        }
    }
}