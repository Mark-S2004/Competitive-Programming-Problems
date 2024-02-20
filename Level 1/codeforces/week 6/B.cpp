#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t;
    unsigned days;
    string s;
    set<char> polycarpMemory;

    cin >> t;
    while (t--)
    {
        days = 0;
        cin >> s;

        for (char c : s)
        {
            polycarpMemory.insert(c);
            if (polycarpMemory.size() > 3)
            {
                ++days;
                polycarpMemory.clear();
            }
            polycarpMemory.insert(c);
        }
        if (polycarpMemory.size())
        {
            ++days;
            polycarpMemory.clear();
        }

        cout << days << endl;
    }
}