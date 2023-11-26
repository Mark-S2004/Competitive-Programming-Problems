#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned Q, x;
    deque<unsigned> A;
    multiset<unsigned> orderedA;
    short query;

    cin >> Q;
    while (Q--)
    {
        cin >> query;
        switch (query)
        {
        case 1:
            cin >> x;
            A.push_back(x);
            break;

        case 2:
            if (orderedA.empty())
            {
                cout << A.front() << '\n';
                A.pop_front();
            }
            else
            {
                cout << *orderedA.begin() << '\n';
                orderedA.erase(orderedA.begin());
            }
            break;

        case 3:
            for (unsigned &x : A)
            {
                orderedA.insert(x);
            }
            A.clear();
            break;

        default:
            break;
        }
    }
}