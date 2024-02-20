#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, i;
    cin >> n;
    while (n)
    {
        deque<short> q;
        if (n > 0)
            for (i = 1; i <= n; i++)
                q.push_back(i);
        else
            for (i = 1; i <= n; i--)
                q.push_back(i);
        cout << "Discarded cards:";
        while (q.size() > 2)
        {
            cout << ' ' << q.front() << ',';
            q.pop_front();
            q.push_back(q.front());
            q.pop_front();
        }
        if (q.size() == 2)
            cout << ' ' << q.front();
        cout << "\nRemaining card: " << q.back() << '\n';

        cin >> n;
    }
}