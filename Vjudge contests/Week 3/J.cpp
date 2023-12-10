#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short q;
    int n, k, i, j;
    string emptyLine;

    cin >> q;
    while (q--)
    {
        getline(cin, emptyLine);
        cin >> n >> k;
        int a[k], t[k], temperatures[k];
        for (i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        for (i = 0; i < k; i++)
        {
            cin >> t[i];
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < k; j++)
            {
                temperatures[j] = t[j] + abs(a[j] - 1 - i);
            }
            cout << *min_element(temperatures, temperatures + k) << " ";
        }
        cout << endl;
    }
}