#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n, m, i, count = 0;

    cin >> n >> m;
    int ai, b[m];
    priority_queue<int, vector<int>, greater<int>> aQ, bQ;
    unordered_map<int, unsigned> res;

    while (n--)
    {
        cin >> ai;
        aQ.push(ai);
    }
    for (i = 0; i < m; ++i)
    {
        cin >> b[i];
        bQ.push(b[i]);
    }

    while (bQ.size())
    {
        while (aQ.size() && aQ.top() <= bQ.top())
        {
            aQ.pop();
            ++count;
        }
        res[bQ.top()] = count;
        bQ.pop();
    }
    for (int bi : b)
        cout << res[bi] << ' ';
}