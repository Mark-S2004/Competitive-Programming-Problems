#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hamming.in", "r", stdin);

    short T, n, count11, count10, count21, count20, i;
    string binary;

    cin >> T;
    while (T--)
    {
        cin >> n;
        count11 = 0;
        count21 = 0;

        cin >> binary;
        for (i = 0; i < n; ++i)
        {
            if (binary[i] == '1')
                ++count11;
        }
        count10 = n - count11;

        cin >> binary;
        for (i = 0; i < n; ++i)
        {
            if (binary[i] == '1')
                ++count21;
        }
        count20 = n - count21;

        cout << min(count11, count20) + min(count10, count21) << '\n';
    }
}