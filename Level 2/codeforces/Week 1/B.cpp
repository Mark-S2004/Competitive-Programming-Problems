#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, q, i, ai;
    int x, y;
    unordered_map<int, vector<int>> buses;

    cin >> n >> q;
    for (i = 0; i < n; ++i)
    {
        cin >> ai;
        buses[ai].push_back(i);
    }
    while (q--)
    {
        cin >> x >> y;
        if (y <= int(buses[x].size()))
            cout << buses[x][y - 1] + 1 << '\n';
        else
            cout << "-1\n";
    }
}