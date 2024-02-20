#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t;
    unsigned n, q, i, l, r, k, ai;
    long long unsigned sum;

    scanf("%hu", &t);
    while (t--)
    {
        scanf("%u %u", &n, &q);
        unsigned long long a[n];
        for (i = 0; i < n; i++)
        {
            scanf("%u", &ai);
            if (i)
                a[i] = (long long unsigned)ai + a[i - 1];
            else
                a[i] = (long long unsigned)ai;
        }
        while (q--)
        {
            scanf("%u %u %u", &l, &r, &k);
            l--;
            r--;
            sum = ((r - l + 1) * k) + (a[n - 1] - a[r]);
            if (l)
                sum += a[l - 1];
            if (sum % 2 == 0)
                cout << "NO" << endl;
            else
                cout << "YES" << endl;
        }
    }
}