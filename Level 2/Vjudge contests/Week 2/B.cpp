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

    short n, firstLetterFrequency[26] = {0}, x = 0;
    string name;

    cin >> n;
    while (n--)
    {
        cin >> name;
        ++firstLetterFrequency[name[0] - 'a'];
    }
    for (short frequency : firstLetterFrequency)
    {
        x += nCr(frequency / 2, 2);
        x += nCr(ceil(frequency / 2.0), 2);
    }

    cout << x;
}