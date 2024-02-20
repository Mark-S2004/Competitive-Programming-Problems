#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n;
    string name;
    map<string, unsigned> database;
    cin >> n;
    while (n--)
    {
        cin >> name;
        if (database.find(name) == database.end())
        {
            cout << "OK" << '\n';
            database[name] = 0;
        }
        else
        {
            database[name]++;
            cout << name + to_string(database[name]) << '\n';
        }
    }
}