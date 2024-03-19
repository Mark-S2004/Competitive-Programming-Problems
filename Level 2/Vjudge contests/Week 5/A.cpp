#include <bits/stdc++.h>
using namespace std;

bool visited[10001] = {false};
void searchDepthFirst(vector<vector<short>> &adjacencyList, short node)
{
    visited[node] = true;
    for (auto neighbour : adjacencyList[node])
        if (!visited[neighbour])
            searchDepthFirst(adjacencyList, neighbour);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short N, M, u, v, i, connectedComponents = 0;

    cin >> N >> M;
    if (M != N - 1)
    {
        cout << "NO";
        return 0;
    }
    vector<vector<short>> adjacencyList(N + 1);
    while (M--)
    {
        cin >> u >> v;
        adjacencyList[u].push_back(v);
        adjacencyList[v].push_back(u);
    }

    for (i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            ++connectedComponents;
            searchDepthFirst(adjacencyList, i);
        }
    }

    if (connectedComponents == 1)
        cout << "YES";
    else
        cout << "NO";
}