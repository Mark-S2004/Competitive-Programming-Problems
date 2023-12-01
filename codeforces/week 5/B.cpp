#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, r, c;
    char board;

    cin >> n >> r >> c;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board;
            if (i == r && j == c)
            {
                if (board == 'O')
                    cout << "Yes";
                else
                    cout << "No";
            }
        }
    }
}