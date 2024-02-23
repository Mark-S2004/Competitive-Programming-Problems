#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, k, i, nPrime;
    bool found;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        found = false;
        nPrime = n;

        for (i = 2; i * i <= nPrime; ++i)
        {
            while (nPrime % i == 0 && !found)
            {
                if (k > n / i)
                    found = false;
                else
                {
                    found = true;
                    break;
                }
                nPrime /= i;
            }
            if (found)
                break;
        }
        if (found)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}