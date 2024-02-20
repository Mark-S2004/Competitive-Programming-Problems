using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, minExtra = 101, maxCorrect = 0, minWrong = 101, i, a, tl = -1;

    cin >> n >> m;
    for (i = 0; i < n; ++i)
    {
        cin >> a;
        minExtra = min(minExtra, a);
        maxCorrect = max(maxCorrect, a);
    }
    for (i = 0; i < m; ++i)
    {
        cin >> a;
        minWrong = min(minWrong, a);
    }
    minExtra *= 2;
    for (i = maxCorrect; i < minWrong; ++i)
    {
        if (i >= minExtra)
        {
            tl = i;
            break;
        }
    }

    cout << tl;
}