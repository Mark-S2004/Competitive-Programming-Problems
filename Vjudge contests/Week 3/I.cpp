#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short unsigned n, i1, i2, cleanRowsCount, variations[51] = {0}, variationsIdx = 1;

    cin >> n;
    string rows[n];
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    for (i1 = 0; i1 < n; i1++)
    {
        getline(cin, rows[i1]);
        rows[0][n] = 'O';
    }

    variations[0] = 1;
    for (i1 = 0; i1 < n - 1; i1++)
    {
        if (rows[i1][n] == 'X')
            continue;
        cleanRowsCount = 1;
        for (i2 = i1 + 1; i2 < n; i2++)
        {
            if (rows[i2][n] == 'X')
                continue;
            if (rows[i1] == rows[i2])
            {
                cleanRowsCount++;
                rows[i2][n] = 'X';
            }
        }
        if (cleanRowsCount > 1)
            variations[variationsIdx++] = cleanRowsCount;
    }
    cout << *max_element(variations, variations + 51) << endl;
}