#include <bits/stdc++.h>
using namespace std;
#define ll long long

int findMaxPassengers(vector<vector<pair<short, ll>>> &mapAdjacencyList, short startCity, short destination)
{
    short city;
    ll maxPassengers;
    vector<ll> cityMaxPassengers(mapAdjacencyList.size(), 0);
    cityMaxPassengers[startCity] = INT64_MAX;
    priority_queue<pair<ll, short>> nextCityToVisit;
    nextCityToVisit.push({INT64_MAX, startCity});
    while (nextCityToVisit.size())
    {
        city = nextCityToVisit.top().second;
        maxPassengers = nextCityToVisit.top().first;
        nextCityToVisit.pop();
        if (city == destination)
            return maxPassengers;
        if (maxPassengers != cityMaxPassengers[city])
            continue;
        for (auto neighbour : mapAdjacencyList[city])
            if (cityMaxPassengers[neighbour.first] < min(maxPassengers, neighbour.second))
            {
                cityMaxPassengers[neighbour.first] = min(maxPassengers, neighbour.second);
                nextCityToVisit.push({cityMaxPassengers[neighbour.first], neighbour.first});
            }
    }
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short N, R, startCity, destination;
    ll passengersCount, scenario = 1, maxPassengers;

    while (cin >> N >> R, N && R)
    {
        vector<vector<pair<short, ll>>> mapAdjacencyList(N + 1);
        while (R--)
        {
            cin >> startCity >> destination >> passengersCount;
            mapAdjacencyList[startCity].push_back({destination, passengersCount});
            mapAdjacencyList[destination].push_back({startCity, passengersCount});
        }
        cin >> startCity >> destination >> passengersCount;

        maxPassengers = findMaxPassengers(mapAdjacencyList, startCity, destination);

        cout << "Scenario #" << scenario++ << '\n';
        cout << "Minimum Number of Trips = " << ceil(passengersCount / double(maxPassengers - 1)) << "\n\n";
    }
}