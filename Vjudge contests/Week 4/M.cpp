#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, k, min1, max1, min2, max2;
    unsigned int fights = 0;
    deque<int> q1, q2;

    cin >> n;
    cin >> n;
    while (n--)
    {
        cin >> k;
        q1.push_back(k);
    }
    cin >> n;
    while (n--)
    {
        cin >> k;
        q2.push_back(k);
    }

    min1 = *min_element(q1.begin(), q1.end());
    max1 = *max_element(q1.begin(), q1.end());
    min2 = *min_element(q2.begin(), q2.end());
    max2 = *max_element(q2.begin(), q2.end());
    if ((min1 > min2 && max1 > max2) || (min2 > min1 && max2 > max1))
    {
        while (q1.size() && q2.size())
        {
            if (q1.front() > q2.front())
            {
                q1.push_back(q2.front());
                q2.pop_front();
                q1.push_back(q1.front());
                q1.pop_front();
            }
            else
            {
                q2.push_back(q1.front());
                q1.pop_front();
                q2.push_back(q2.front());
                q2.pop_front();
            }
            fights++;
        }
        cout << fights << ' ';
        if (q1.size())
            cout << 1;
        else
            cout << 2;
    }
    else
        cout << -1;
}