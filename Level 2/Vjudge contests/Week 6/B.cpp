#include <bits/stdc++.h>
using namespace std;
#define ll long long

void get1nPath(stack<int> &path, vector<int> &parents, int n)
{
    while (n)
    {
        path.push(n);
        n = parents[n];
    }
}

void get1nShortestPath(int n, vector<vector<pair<int, int>>> &adjacencyList, stack<int> &path)
{
    int node;
    ll distance;
    vector<ll> distances(n + 1, INT64_MAX);
    vector<int> parents(n + 1, 0);
    distances[1] = 0;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> nextnodeToVisit;
    nextnodeToVisit.push({0, 1});
    while (nextnodeToVisit.size())
    {
        node = nextnodeToVisit.top().second;
        distance = nextnodeToVisit.top().first;
        nextnodeToVisit.pop();
        if (node == n)
            break;
        if (distances[node] != distance)
            continue;
        for (auto neighbour : adjacencyList[node])
            if (distances[neighbour.first] > neighbour.second + distance)
            {
                distances[neighbour.first] = neighbour.second + distance;
                nextnodeToVisit.push({distances[neighbour.first], neighbour.first});
                parents[neighbour.first] = node;
            }
    }
    get1nPath(path, parents, n);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, a, b, w;

    cin >> n >> m;
    vector<vector<pair<int, int>>> adjacencyList(n + 1);
    stack<int> path;
    while (m--)
    {
        cin >> a >> b >> w;
        adjacencyList[a].push_back({b, w});
        adjacencyList[b].push_back({a, w});
    }

    get1nShortestPath(n, adjacencyList, path);
    if (path.size() == 1)
        cout << -1;
    else
        while (path.size())
        {
            cout << path.top() << ' ';
            path.pop();
        }
}