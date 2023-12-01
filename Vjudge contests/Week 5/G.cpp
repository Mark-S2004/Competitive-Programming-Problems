#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, i, j;
    string ans = "YES";
    char c, x, notX;

    cin >> n;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cin >> c;
            if (!i && !j)
                x = c;
            else if (!i && j == 1)
                notX = c;
            else if (i == j || j == n - 1 - i)
            {
                if (c != x)
                    ans = "NO";
            }
            else if (c != notX)
                ans = "NO";
        }
    }
    if (x == notX)
        ans = "NO";

    cout << ans;
}