#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned T, open, close;
    string s;

    cin >> T;
    while (T--)
    {
        open = 0;
        close = 0;

        cin >> s;
        for (char c : s)
        {
            if (c == '(')
                ++open;
            else
            {
                if (open)
                    --open;
                else
                    ++close;
            }
        }
        if ((open + close) % 2 == 1)
        {
            cout << -1 << '\n';
            continue;
        }
        cout << max(open, close) << '\n';
    }
}