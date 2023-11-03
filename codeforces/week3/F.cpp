#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned int n, k, day, sumPenalty;
    int i, m;

    cin >> n >> m;
    unsigned int a[n];
    for (i = 0; i < (int)n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (i = 1; i < (int)n; i++)
        a[i] += a[i - 1];
    for (k = 1; k <= n; k++)
    {
        sumPenalty = 0;
        day = 1;
        for (i = k - 1; i >= 0; i = i - m)
        {
            if (i - m >= 0)
                sumPenalty += day * (a[i] - a[i - m]);
            else
                sumPenalty += day * a[i];
            day++;
        }
        cout << sumPenalty << ' ';
    }
}