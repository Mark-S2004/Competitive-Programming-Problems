#include <bits/stdc++.h>
using namespace std;

bool visited[1000] = {false};
void searchDepthFirst(short brain, vector<vector<short>> &nervousSystem)
{
    visited[brain] = true;
    for (auto neighbourBrain : nervousSystem[brain])
        if (!visited[neighbourBrain])
            searchDepthFirst(neighbourBrain, nervousSystem);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, m, i, brain1, brain2, connectedBrains = 0;

    cin >> n >> m;
    vector<vector<short>> nervousSystem(n);
    for (i = 0; i < m; ++i)
    {
        cin >> brain1 >> brain2;
        nervousSystem[brain1 - 1].push_back(brain2 - 1);
        nervousSystem[brain2 - 1].push_back(brain1 - 1);
    }

    if (m != n - 1)
    {
        cout << "no";
        return 0;
    }
    for (brain1 = 0; brain1 < n; ++brain1)
        if (!visited[brain1])
        {
            ++connectedBrains;
            searchDepthFirst(brain1, nervousSystem);
        }

    if (connectedBrains == 1)
        cout << "yes";
    else
        cout << "no";
}