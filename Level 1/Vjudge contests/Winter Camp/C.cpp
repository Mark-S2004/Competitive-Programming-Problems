#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, k, operations;
    string s;

    cin >> t;
    while (t--)
    {
        cin >> n >> k >> s;

        operations = 0;
        for (int i = 0; i < n; ++i)
            if (s[i] == 'B')
            {
                ++operations;
                i += k - 1;
            }

        cout << operations << endl;
    }
}