#include <bits/stdc++.h>
using namespace std;

bool visited[100000];
pair<int, int> maxBFS(int rootBrain, vector<vector<int>> &nervousSystem)
{
    queue<pair<int, int>> brainsToVisit;
    brainsToVisit.push({rootBrain, 0});
    visited[rootBrain] = true;
    pair<int, int> brain;

    while (brainsToVisit.size())
    {
        brain = brainsToVisit.front();
        brainsToVisit.pop();
        for (auto neighbourBrain : nervousSystem[brain.first])
            if (!visited[neighbourBrain])
            {
                brainsToVisit.push({neighbourBrain, brain.second + 1});
                visited[neighbourBrain] = true;
            }
    }

    return brain;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, brain1, brain2, latency = 0;

    cin >> n >> m;
    vector<vector<int>> nervousSystem(n);
    while (m--)
    {
        cin >> brain1 >> brain2;
        nervousSystem[brain1 - 1].push_back(brain2 - 1);
        nervousSystem[brain2 - 1].push_back(brain1 - 1);
    }

    memset(visited, 0, sizeof visited);
    brain1 = maxBFS(0, nervousSystem).first;
    memset(visited, 0, sizeof visited);
    latency = maxBFS(brain1, nervousSystem).second;

    cout << latency;
}