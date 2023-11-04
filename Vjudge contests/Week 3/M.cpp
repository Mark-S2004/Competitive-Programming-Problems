#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short N, i, j, k, l;
    int maxSum = INT32_MIN, sum;

    cin >> N;
    short prefixSum[N][N];
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            cin >> prefixSum[i][j];
            if (j)
                prefixSum[i][j] += prefixSum[i][j - 1];
            if (i && j)
                prefixSum[i][j - 1] += prefixSum[i - 1][j - 1];
        }
        if (i)
            prefixSum[i][N - 1] += prefixSum[i - 1][N - 1];
    }

    for (k = 0; k < N; k++)
    {
        for (l = 0; l < N; l++)
        {
            for (i = k; i < N; i++)
            {
                for (j = l; j < N; j++)
                {
                    sum = prefixSum[i][j];
                    if (k)
                        sum -= prefixSum[k - 1][j];
                    if (l)
                        sum -= prefixSum[i][l - 1];
                    if (k && l)
                        sum += prefixSum[k - 1][l - 1];
                    maxSum = max(maxSum, sum);
                }
            }
        }
    }
    cout << maxSum << endl;
}