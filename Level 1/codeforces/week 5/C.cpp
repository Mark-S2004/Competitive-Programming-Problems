#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned t, n, m, i, type, correct;

    cin >> t;
    while (t--)
    {
        priority_queue<unsigned> ordered;
        priority_queue<unsigned> prefered;
        correct = 0;

        cin >> n >> m;
        i = n;
        while (i--)
        {
            cin >> type;
            ordered.push(type);
        }
        i = n;
        while (i--)
        {
            cin >> type;
            prefered.push(type);
        }
        while (prefered.size() && ordered.size())
        {
            n = ordered.top();
            m = prefered.top();
            if (n == m)
            {
                ++correct;
                ordered.pop();
                prefered.pop();
            }
            else if (m < n)
                ordered.pop();
            else
                prefered.pop();
        }
        cout << correct << '\n';
    }
}