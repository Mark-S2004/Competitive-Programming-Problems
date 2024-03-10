#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int Egcd(int a, int b, int &x, int &y) // O(log(min(a,b)) and in works with negative a,b
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = Egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int modInv(int a, int m) // o(log(min(a,m)))
{
    int x, y;
    int g = Egcd(a, m, x, y);

    if (g != 1)
        return -1;
    else
        return (x + m) % m;
}

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
        ans *= i++ % MOD;
        ans %= MOD;
        ans *= modInv(div++, MOD);
        ans %= MOD;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short t, n, k, ai, i, numberCount;

    cin >> t;
    while (t--)
    {
        priority_queue<short> a;
        cin >> n >> k;
        short frequency[n + 1] = {0};

        for (i = 0; i < n; ++i)
        {
            cin >> ai;
            ++frequency[ai];
            a.push(ai);
        }
        ai = 0;
        while (k--)
        {
            if (ai != a.top())
                numberCount = 1;
            else
                ++numberCount;
            ai = a.top();
            a.pop();
        }

        cout << nCr(frequency[ai], numberCount) << '\n';
    }
}