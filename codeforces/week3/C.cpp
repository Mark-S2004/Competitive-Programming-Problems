#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short T, n, k, i;
    unsigned int ans;

    cin >> T;
    while (T--)
    {
        ans = 0;
        cin >> n >> k;
        unsigned short a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a, a + n, greater<unsigned short>());
        for (i = 0; i < k; i++)
        {
            ans += a[i];
        }
        cout << ans << endl;
    }
}