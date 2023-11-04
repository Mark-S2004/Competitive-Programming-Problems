#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, m, i, j, k, l;
    int maxPerimeter = INT32_MIN, sum;
    string row;

    cin >> n >> m;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    short prefixSum[n][m];
    for (i = 0; i < n; i++)
    {
        getline(cin, row);
        for (j = 0; j < m; j++)
        {
            prefixSum[i][j] = row[j] - '0';
            if (j)
                prefixSum[i][j] += prefixSum[i][j - 1];
            if (i && j)
                prefixSum[i][j - 1] += prefixSum[i - 1][j - 1];
        }
        if (i)
            prefixSum[i][m - 1] += prefixSum[i - 1][m - 1];
    }

    for (k = 0; k < n; k++)
    {
        for (l = 0; l < m; l++)
        {
            for (i = k; i < n; i++)
            {
                for (j = l; j < m; j++)
                {
                    sum = prefixSum[i][j];
                    if (k)
                        sum -= prefixSum[k - 1][j];
                    if (l)
                        sum -= prefixSum[i][l - 1];
                    if (k && l)
                        sum += prefixSum[k - 1][l - 1];
                    if (!sum)
                        maxPerimeter = max(maxPerimeter, 2 * (i - k + 1) + 2 * (j - l + 1));
                }
            }
        }
    }
    cout << maxPerimeter << endl;
}