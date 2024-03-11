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

    short n, m, cell, i, j, k, row1Count, row0Count, col0Count;
    unsigned long long nonEmptySetsCount = 0;

    cin >> n >> m;
    short col1Count[m] = {0};
    nonEmptySetsCount = n * m;

    for (i = 0; i < n; ++i)
    {
        row1Count = 0;
        for (j = 0; j < m; ++j)
        {
            cin >> cell;
            if (cell)
            {
                ++row1Count;
                ++col1Count[j];
            }
        }
        row0Count = m - row1Count;
        for (k = 2; k <= row1Count; ++k)
            nonEmptySetsCount += nCr(row1Count, k);
        for (k = 2; k <= row0Count; ++k)
            nonEmptySetsCount += nCr(row0Count, k);
    }
    for (i = 0; i < m; ++i)
    {
        col0Count = n - col1Count[i];
        for (k = 2; k <= col1Count[i]; ++k)
            nonEmptySetsCount += nCr(col1Count[i], k);
        for (k = 2; k <= col0Count; ++k)
            nonEmptySetsCount += nCr(col0Count, k);
    }

    cout << nonEmptySetsCount;
}