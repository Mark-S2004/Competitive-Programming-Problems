#include <bits/stdc++.h>
using namespace std;

bool init[100001], goal[100001], visited[100001];
vector<int> flippedNodes;

void flipNodes(vector<vector<int>> &adjacencyList, int node = 1, int level = 0, int evenLevelOps = 0, int oddLevelOps = 0)
{
    visited[node] = true;

    bool nodeValue;
    if (!(level % 2))
        nodeValue = (init[node] + evenLevelOps) % 2;
    else
        nodeValue = (init[node] + oddLevelOps) % 2;
    if (nodeValue ^ goal[node])
    {
        if (!(level % 2))
            ++evenLevelOps;
        else
            ++oddLevelOps;
        flippedNodes.push_back(node);
    }

    for (int child : adjacencyList[node])
        if (!visited[child])
            flipNodes(adjacencyList, child, level + 1, evenLevelOps, oddLevelOps);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, u, v, i;

    cin >> n;
    vector<vector<int>> adjacencyList(n + 1);
    for (i = 0; i < n - 1; ++i)
    {
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }
    for (i = 1; i <= n; ++i)
        cin >> init[i];
    for (i = 1; i <= n; ++i)
        cin >> goal[i];

    flipNodes(adjacencyList);

    cout << flippedNodes.size() << '\n';
    for (int node : flippedNodes)
        cout << node << '\n';
}