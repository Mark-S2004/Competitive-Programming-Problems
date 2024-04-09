#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll getStartToDestinationMinTime(int start, int end, int n, vector<vector<pair<int, short>>> &cityAdjacencyList)
{
    int city;
    short time;
    vector<ll> cityTime(n + 1, INT64_MAX);
    cityTime[start] = 0;
    priority_queue<pair<short, int>, vector<pair<short, int>>, greater<pair<short, int>>> nextCityToVisit;
    nextCityToVisit.push({0, start});
    while (nextCityToVisit.size())
    {
        city = nextCityToVisit.top().second;
        time = nextCityToVisit.top().first;
        nextCityToVisit.pop();
        if (city == end)
            return time;
        if (cityTime[city] != time)
            continue;
        for (auto neighbour : cityAdjacencyList[city])
            if (cityTime[neighbour.first] > neighbour.second + time)
            {
                cityTime[neighbour.first] = neighbour.second + time;
                nextCityToVisit.push({cityTime[neighbour.first], neighbour.first});
            }
    }
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll minTime;
    int t, n, m, start, end, u, v;
    short time;

    cin >> t;
    while (t--)
    {
        cin >> n >> m >> start >> end;
        vector<vector<pair<int, short>>> cityAdjacencyList(n + 1);
        while (m--)
        {
            cin >> u >> v >> time;
            cityAdjacencyList[u].push_back({v, time});
            cityAdjacencyList[v].push_back({u, time});
        }

        minTime = getStartToDestinationMinTime(start, end, n, cityAdjacencyList);
        if (minTime == -1)
            cout << "NONE";
        else
            cout << minTime;
        cout << '\n';
    }
}