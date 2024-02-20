#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short m, n;
    unsigned points;
    unsigned long long hayPoints;
    string word;
    unordered_map<string, unsigned> dictionary;
    unordered_map<string, unsigned>::iterator it;

    cin >> m >> n;
    while (m--)
    {
        cin >> word >> points;
        dictionary[word] = points;
    }
    while (n--)
    {
        hayPoints = 0;

        while (cin >> word, word != ".")
        {
            it = dictionary.find(word);
            if (it != dictionary.end())
                hayPoints += it->second;
        }

        cout << hayPoints << '\n';
    }
}