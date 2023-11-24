#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i, x, collisionMoment = INT32_MAX;
    deque<int> position;

    cin >> n;
    char direction[n];
    for (i = 0; i < n; i++)
    {
        cin >> direction[i];
    }
    cin >> x;
    position.push_back(x);
    for (i = 1; i < n; i++)
    {
        cin >> x;
        position.push_back(x);
        if (direction[i - 1] == 'R' && direction[i] == 'L')
            collisionMoment = min(collisionMoment, position.back() - position.front());
        position.pop_front();
    }
    if (collisionMoment == INT32_MAX)
        collisionMoment = -1;
    else
        collisionMoment /= 2;
    cout << collisionMoment << endl;
}