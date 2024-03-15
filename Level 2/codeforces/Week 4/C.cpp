#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short t, n, i, lastOneIdx;
    int operations;
    bool start;

    cin >> t;
    while (t--)
    {
        cin >> n;
        short ribbon[n];
        stack<short> zeroIdxs;
        operations = 0;
        start = false;
        lastOneIdx = 0;

        for (i = 0; i < n; ++i)
        {
            cin >> ribbon[i];
            if (ribbon[i])
            {
                start = true;
                lastOneIdx = i;
            }
            if (!ribbon[i] && start)
                zeroIdxs.push(i);
        }
        if (zeroIdxs.size())
            while (zeroIdxs.size() && zeroIdxs.top() > lastOneIdx)
                zeroIdxs.pop();
        for (i = n - 1; i >= 0 && zeroIdxs.size(); --i)
        {
            if (ribbon[i])
            {
                ++operations;
                ribbon[zeroIdxs.top()] = 1;
                zeroIdxs.pop();
            }
        }

        cout << operations << '\n';
    }
}