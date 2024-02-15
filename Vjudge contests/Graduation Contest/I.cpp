using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a;

    cin >> n;
    priority_queue<int> boxers;
    set<int> team;
    while (n--)
    {
        cin >> a;
        boxers.push(a);
    }
    while (boxers.size())
    {
        a = boxers.top();
        if (team.find(a + 1) == team.end())
            team.insert(a + 1);
        else if (team.find(a) == team.end())
            team.insert(a);
        else if (a - 1)
            team.insert(a - 1);
        boxers.pop();
    }

    cout << team.size();
}