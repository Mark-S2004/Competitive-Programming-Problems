#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short T, n, j;
    bool ans;

    cin >> T;
    while (T--)
    {
        cin >> n;
        map<unsigned short, unsigned short> i, k;
        unsigned short a[n];
        ans = false;

        for (j = 0; j < n; ++j)
        {
            cin >> a[j];
            if (j > 1)
                k[a[j]] = j;
        }
        i[a[0]] = 0;
        for (j = 1; j < n - 1; ++j)
        {
            if (i.begin()->first < a[j] && k.begin()->first < a[j])
            {
                ans = true;
                cout << "YES" << endl;
                cout << i.begin()->second + 1 << ' ' << j + 1 << ' ' << k.begin()->second + 1 << endl;
                break;
            }
            i[a[j]] = j;
            k.erase(a[j]);
        }
        if (!ans)
            cout << "NO" << endl;
    }
}