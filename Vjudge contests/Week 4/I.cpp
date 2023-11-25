#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t;
    int n, k, i, damage;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<pair<int, int>> monsters(n);
        for (i = 0; i < n; i++)
            cin >> monsters[i].second;
        for (i = 0; i < n; i++)
            cin >> monsters[i].first;
        sort(monsters.begin(), monsters.end());
        i = 0;
        damage = k;
        while (k > 0 && i < n)
        {
            if (monsters[i].second - damage > 0)
            {
                k -= monsters[i].first;
                damage += k;
            }
            else
                i++;
        }

        if (i == n)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}