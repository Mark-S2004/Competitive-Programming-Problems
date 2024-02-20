#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t, ei, zi, pi, ci, i;
    string s;

    cin >> t;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (t--)
    {
        getline(cin, s);
        for (i = 0; i < s.size(); i++)
        {
            switch (s[i])
            {
            case 'e':
                ei = i;
                break;

            case 'z':
                zi = i;
                break;

            case 'p':
                pi = i;
                break;

            case 'c':
                ci = i;
                break;

            default:
                break;
            }
        }
        if (ci < ei || ci < zi || ci < pi || pi < zi)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
}