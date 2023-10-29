#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned int n, m, l, r;
    short type;

    scanf("%u", &n);
    unsigned int arr[n];
    unsigned long long prefixSum[n], prefixSumSorted[n];
    for (l = 0; l < n; l++)
    {
        scanf("%u", &arr[l]);
        prefixSum[l] = (long long unsigned)arr[l];
        if (l)
            prefixSum[l] += prefixSum[l - 1];
    }
    sort(arr, arr + n);
    prefixSumSorted[0] = arr[0];
    for (l = 0; l < n; l++)
    {
        if (l)
            prefixSumSorted[l] = arr[l] + prefixSumSorted[l - 1];
    }

    scanf("%u", &m);
    while (m--)
    {
        scanf("%hd %u %u", &type, &l, &r);
        l--;
        r--;
        if (type == 1)
        {
            if (l)
                cout << prefixSum[r] - prefixSum[l - 1];
            else
                cout << prefixSum[r];
        }
        else
        {
            if (l)
                cout << prefixSumSorted[r] - prefixSumSorted[l - 1];
            else
                cout << prefixSumSorted[r];
        }
        cout << endl;
    }
}