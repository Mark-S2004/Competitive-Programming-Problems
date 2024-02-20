#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string orig = "codeforces", s;
    int t, no_differs;

    cin >> t;
    while (t--)
    {
        cin >> s;
        no_differs = 0;
        for (int i = 0; i < 10; ++i)
            if (orig[i] != s[i])
                ++no_differs;
        cout << no_differs << endl;
    }
}