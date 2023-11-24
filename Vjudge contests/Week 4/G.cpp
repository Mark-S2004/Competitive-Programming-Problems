#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t;
    unsigned n, si;
    unsigned long long power;

    cin >> t;
    while (t--)
    {
        cin >> n;
        power = 0;
        priority_queue<unsigned> s;
        while (n--)
        {
            cin >> si;
            if (si)
                s.push(si);
            else
            {
                if (s.size())
                {
                    power += s.top();
                    s.pop();
                }
            }
        }
        cout << power << endl;
    }
}