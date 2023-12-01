#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t, n;

    cin >> t;
    while (t--)
    {
        cin >> n;
        if (n)
            cout << 10;
        else
            cout << 0;
        cout << '\n';
    }
}