#include <bits/stdc++.h>
using namespace std;

bool visited[5000];
void traverseDepthFirst(short creature, short &chainSize, vector<vector<short>> &adjacencyList)
{
    visited[creature] = true;
    ++chainSize;
    for (short prey : adjacencyList[creature])
        if (!visited[prey])
            traverseDepthFirst(prey, chainSize, adjacencyList);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short C, R, idx, maxChain, chainSize;
    string creatureName, prey, predator;

    while (cin >> C >> R, C || R)
    {
        unordered_map<string, short> creatureIdx;
        vector<vector<short>> adjacencyList(C);
        maxChain = 0;
        for (idx = 0; idx < C; ++idx)
        {
            cin >> creatureName;
            creatureIdx[creatureName] = idx;
        }
        while (R--)
        {
            cin >> prey >> predator;
            adjacencyList[creatureIdx[predator]].push_back(creatureIdx[prey]);
            adjacencyList[creatureIdx[prey]].push_back(creatureIdx[predator]);
        }

        for (idx = 0; idx < C; ++idx)
        {
            chainSize = 0;
            memset(visited, 0, sizeof visited);
            traverseDepthFirst(idx, chainSize, adjacencyList);
            maxChain = max(maxChain, chainSize);
        }

        cin.ignore();
        getline(cin, creatureName);
        cout << maxChain << '\n';
    }
}