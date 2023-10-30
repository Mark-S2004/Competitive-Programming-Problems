#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    unsigned int n, i, l, r, m;

    getline(cin, s);
    n = s.size();
    unsigned int prefixSum[n];
    if (s[0] == s[1])
        prefixSum[0] = 1;
    else
        prefixSum[0] = 0;
    for (i = 1; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
            prefixSum[i] = prefixSum[i - 1] + 1;
        else
            prefixSum[i] = prefixSum[i - 1];
    }
    prefixSum[n - 1] = prefixSum[n - 2];
    scanf("%u", &m);
    while (m--)
    {
        scanf("%u %u", &l, &r);
        l--;
        r--;
        if (l)
        {
            printf("%u", prefixSum[r - 1]);
            cout << prefixSum[l - 1] << endl;
            cout << prefixSum[r - 1] - prefixSum[l - 1];
        }
        else
            cout << prefixSum[r - 1];
        cout << endl;
    }
}