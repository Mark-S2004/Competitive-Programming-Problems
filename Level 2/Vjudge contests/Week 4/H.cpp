#include <bits/stdc++.h>
using namespace std;
#define COUNT_SET_BITS(x) __builtin_popcount(x)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short T, N, S, permutation, coin, maxPaid;

    cin >> T;
    while (T--)
    {
        cin >> N >> S;
        short coins[N], sum;
        maxPaid = 0;

        for (coin = 0; coin < N; ++coin)
        {
            cin >> coins[coin];
        }
        for (permutation = 1; permutation < pow(2, N); ++permutation)
        {
            sum = 0;
            priority_queue<short, vector<short>, greater<short>> paidCoins;
            for (coin = 0; coin < N; ++coin)
                if (permutation & (1 << coin))
                {
                    paidCoins.push(coins[coin]);
                    sum += coins[coin];
                }
            if (sum - paidCoins.top() < S && sum >= S)
                maxPaid = max(maxPaid, short(COUNT_SET_BITS(permutation)));
        }

        cout << maxPaid << '\n';
    }
}