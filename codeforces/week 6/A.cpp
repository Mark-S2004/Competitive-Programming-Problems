#include <bits/stdc++.h>
using namespace std;

#define endl '\n';

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t, i;
    char letter;
    string position;

    cin >> t;
    while (t--)
    {
        cin >> position;
        for (i = 1; i <= 8; ++i)
            if (i != stoi(position.substr(1)))
                cout << position[0] << i << endl;
        for (i = 0; i < 8; ++i)
        {
            letter = i + 'a';
            if (letter != position[0])
                cout << letter << position[1] << endl;
        }
    }
}