#include <bits/stdc++.h>
using namespace std;
#define ll long long

void findCityMinCost(vector<vector<pair<int, ll>>> &cityAdjacencyList, vector<ll> &costs)
{
    int city, n = cityAdjacencyList.size() - 1;
    ll cost;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> nextCityToVisit;
    for (city = 1; city <= n; ++city)
        nextCityToVisit.push({costs[city], city});
    while (nextCityToVisit.size())
    {
        city = nextCityToVisit.top().second;
        cost = nextCityToVisit.top().first;
        nextCityToVisit.pop();
        if (cost != costs[city])
            continue;
        for (auto neighbour : cityAdjacencyList[city])
            if (costs[neighbour.first] > neighbour.second + cost)
            {
                costs[neighbour.first] = neighbour.second + cost;
                nextCityToVisit.push({costs[neighbour.first], neighbour.first});
            }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, u, v, i;
    ll w;

    cin >> n >> m;
    vector<vector<pair<int, ll>>> cityAdjacencyList(n + 1);
    vector<ll> costs(n + 1);
    while (m--)
    {
        cin >> u >> v >> w;
        w *= 2;
        cityAdjacencyList[u].push_back({v, w});
        cityAdjacencyList[v].push_back({u, w});
    }
    for (i = 1; i <= n; ++i)
        cin >> costs[i];

    findCityMinCost(cityAdjacencyList, costs);

    for (i = 1; i <= n; ++i)
        cout << costs[i] << ' ';
}