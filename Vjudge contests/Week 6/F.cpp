#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, m, a, maxParticipants, ans = 0;
    short st = 0, end = 100, md;
    unordered_map<unsigned short, unsigned short> packageFrequency;

    cin >> n >> m;
    while (m--)
    {
        cin >> a;
        ++packageFrequency[a];
    }

    while (st <= end)
    {
        md = (st + end) / 2;
        if (!md)
        {
            md = 1;
            st = 1;
        }
        maxParticipants = 0;
        for (auto package : packageFrequency)
            maxParticipants += package.second / md;
        if (maxParticipants >= n)
        {
            ans = md;
            st = md + 1;
        }
        else
            end = md - 1;
    }

    cout << ans;
}