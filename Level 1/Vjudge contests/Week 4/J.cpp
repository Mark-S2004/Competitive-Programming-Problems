#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n, k, i;

    cin >> n >> k;
    unsigned a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    if (k)
    {
        k--;
        if (a[k] == a[k + 1])
            cout << -1 << endl;
        else
            cout << a[k] << endl;
    }
    else
    {
        if (a[0] >= 2)
            cout << a[0] - 1 << endl;
        else
            cout << -1 << endl;
    }
}