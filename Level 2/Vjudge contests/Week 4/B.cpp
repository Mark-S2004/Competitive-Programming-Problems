#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short t, bitIdx;
    // lsb1 least signifcant set bit
    int x, lsb1;

    cin >> t;
    while (t--)
    {
        cin >> x;
        bitIdx = 0;

        if (x == 1)
        {
            cout << 3 << '\n';
            continue;
        }
        while (true)
        {
            lsb1 = 1 << bitIdx++;
            if (x & lsb1)
                break;
        }
        if (!(x - lsb1))
            lsb1 += 1;

        cout << lsb1 << '\n';
    }
}