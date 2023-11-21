#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, m, i, lastChild = 0;

    cin >> n >> m;
    short a[n];
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = 1 + ((a[i] - 1) / m);
        if (a[i] >= a[lastChild])
            lastChild = i;
    }
    cout << lastChild + 1 << endl;
}