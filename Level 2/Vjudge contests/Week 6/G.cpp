#include <bits/stdc++.h>
using namespace std;
#define ll long long

pair<int, int> searchDijkstra(vector<vector<pair<int, int>>> &mapAdjacencyList, int arrivalCity)
{
    int n = mapAdjacencyList.size(), city, distance, maxDistance, maxDistanceCitiesCount = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nextCityToVisit;
    vector<int> cityDistances(n, -1);

    nextCityToVisit.push({0, arrivalCity});
    cityDistances[arrivalCity] = 0;
    while (nextCityToVisit.size())
    {
        distance = nextCityToVisit.top().first;
        city = nextCityToVisit.top().second;
        nextCityToVisit.pop();
        if (distance != cityDistances[city])
            continue;
        for (auto neighbour : mapAdjacencyList[city])
            if (cityDistances[neighbour.first] == -1 || cityDistances[neighbour.first] > neighbour.second + distance)
            {
                cityDistances[neighbour.first] = neighbour.second + distance;
                nextCityToVisit.push({cityDistances[neighbour.first], neighbour.first});
            }
    }

    maxDistance = *max_element(cityDistances.begin(), cityDistances.end());
    for (city = 0; city < n; ++city)
        if (cityDistances[city] == maxDistance)
            ++maxDistanceCitiesCount;
    return {maxDistance, maxDistanceCitiesCount};
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, Q, city1, city2, L, arrivalCity;
    pair<int, int> distantCities;

    cin >> N >> M >> Q;
    vector<vector<pair<int, int>>> mapAdjacencyList(N);
    while (M--)
    {
        cin >> city1 >> city2 >> L;
        mapAdjacencyList[city1].push_back({city2, L});
        mapAdjacencyList[city2].push_back({city1, L});
    }
    while (Q--)
    {
        cin >> arrivalCity;
        distantCities = searchDijkstra(mapAdjacencyList, arrivalCity);
        cout << distantCities.first << ' ' << distantCities.second << '\n';
    }
}