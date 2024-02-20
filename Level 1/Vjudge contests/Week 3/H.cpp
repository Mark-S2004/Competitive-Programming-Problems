#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned int n, i, equalCutsCount = 0;

    cin >> n;
    int prefixSum[n];
    cin >> prefixSum[0];
    for (i = 1; i < n; i++)
    {
        cin >> prefixSum[i];
        prefixSum[i] += prefixSum[i - 1];
    }
    for (i = 0; i < n - 1; i++)
    {
        if (prefixSum[i] == prefixSum[n - 1] - prefixSum[i])
            equalCutsCount++;
    }
    cout << equalCutsCount << endl;
}