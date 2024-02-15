using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int k, i, j, maxX = 0, dotCount, xCount;

    cin >> s >> k;
    for (i = 0; i < s.size(); ++i)
    {
        dotCount = 0;
        xCount = 0;
        j = i;
        while (s[j] == 'X' || dotCount < k)
        {
            if (s[j] == '.')
                ++dotCount;
            ++xCount;
            ++j;
            if (j == s.size())
                break;
        }
        maxX = max(maxX, xCount);
    }

    cout << maxX << endl;
}