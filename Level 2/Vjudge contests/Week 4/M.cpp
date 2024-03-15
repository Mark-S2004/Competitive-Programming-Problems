#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short t;
    int n, k, a, i, bit, result;

    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<int> zeroFrequency(31, n);
        result = INT32_MAX;

        for (i = 0; i < n; ++i)
        {
            cin >> a;
            result &= a;
            for (bit = 0; bit <= 30; ++bit)
                if (a & (1 << bit))
                    --zeroFrequency[bit];
        }
        for (bit = 30; bit >= 0; --bit)
        {
            if (zeroFrequency[bit] <= k)
            {
                result |= (1 << bit);
                k -= zeroFrequency[bit];
            }
        }

        cout << result << '\n';
    }
}