#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned int N, i, j;
    unsigned short Q;

    scanf("%u", &N);
    int prefixSum[N];
    for (i = 0; i < N; i++)
    {
        scanf("%d", &prefixSum[i]);
        if (i)
            prefixSum[i] += prefixSum[i - 1];
    }
    scanf("%hu", &Q);
    while (Q--)
    {
        scanf("%u %u", &i, &j);
        if (i)
            cout << prefixSum[j] - prefixSum[i - 1] << endl;
        else
            cout << prefixSum[j] << endl;
    }
}