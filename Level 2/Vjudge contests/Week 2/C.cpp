#include <bits/stdc++.h>
using namespace std;

unsigned long long nCr(int n, int r)
{
    if (r > n)
        return 0;
    if (r == n)
        return 1;

    r = max(r, n - r);
    unsigned long long ans = 1, div = 1, i = r + 1;
    while (i <= n)
    {
        ans *= i++;
        ans /= div++;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short q;
    long long sdifferentCount;
    string s, t;
    bool aFound;

    cin >> q;
    while (q--)
    {
        cin >> s >> t;
        sdifferentCount = 1;
        aFound = false;

        if (t == "a")
        {
            cout << 1 << '\n';
            continue;
        }
        for (char c : t)
            if (c == 'a')
            {
                cout << -1 << '\n';
                aFound = true;
                break;
            }
        if (aFound)
            continue;

        for (int i = 1; i <= s.length(); ++i)
            sdifferentCount += nCr(s.length(), i);
        cout << sdifferentCount << '\n';
    }
}