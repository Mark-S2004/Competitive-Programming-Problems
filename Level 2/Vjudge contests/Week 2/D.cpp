#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long substringsCount = 0, length = 0;
    short k;
    string s;
    char letter;
    unordered_set<char> availableLetters;

    cin >> n >> k >> s;
    while (k--)
    {
        cin >> letter;
        availableLetters.insert(letter);
    }
    for (char c : s)
    {
        if (availableLetters.find(c) != availableLetters.end())
            ++length;
        else
        {
            substringsCount += (length * (length + 1)) / 2;
            length = 0;
        }
    }
    substringsCount += (length * (length + 1)) / 2;

    cout << substringsCount;
}