#include <bits/stdc++.h>
using namespace std;

int getLuckyIdx(string n, int i, int idx)
{
    if (i == int(n.size()))
        return idx;

    if (n[(n.size() - 1) - i] == '7')
        idx += pow(2, i);
    idx += pow(2, i);

    return getLuckyIdx(n, ++i, idx);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string n;

    cin >> n;

    cout << getLuckyIdx(n, 0, 0) << '\n';
}