#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, a, b, x;

    cin >> t;
    while (t--)
    {
        cin >> a >> b;

        x = a & b;

        cout << (a ^ x) + (b ^ x) << '\n';
    }
}