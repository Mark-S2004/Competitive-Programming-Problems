#include <bits/stdc++.h>
using namespace std;
#define ll long long

int searchMinTimeToFloor(vector<vector<pair<int, int>>> &floorsAdjacencyList, int n, int k)
{
    int floor, time, i;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> nextFloorToVisit;
    vector<int> floorTime(1000, INT32_MAX);

    for (i = 1; i <= n; ++i)
    {
        nextFloorToVisit.push({0, i});
        floorTime[i] = 0;
    }
    while (nextFloorToVisit.size())
    {
        time = nextFloorToVisit.top().first;
        floor = nextFloorToVisit.top().second;
        nextFloorToVisit.pop();
        if (floor / 10 == k)
            return time;
        if (time != floorTime[floor])
            continue;
        for (auto neighbour : floorsAdjacencyList[floor])
            if (floorTime[neighbour.first] > time + neighbour.second)
            {
                floorTime[neighbour.first] = time + neighbour.second;
                nextFloorToVisit.push({floorTime[neighbour.first], neighbour.first});
            }
    }

    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k, elevator, elevators, floor, prevFloor, i, j, time;
    string inputLine;

    while (cin >> n >> k)
    {
        int elevatorTime[n + 1];
        vector<vector<pair<int, int>>> floorsAdjacencyList(1000);
        vector<vector<int>> elevatorsInFloor(100);
        for (elevator = 1; elevator <= n; ++elevator)
            cin >> elevatorTime[elevator];
        cin.ignore();
        for (elevator = 1; elevator <= n; ++elevator)
        {
            getline(cin, inputLine);
            stringstream floorStream(inputLine);
            floorStream >> prevFloor;
            elevatorsInFloor[prevFloor].push_back(elevator);
            while (floorStream >> floor)
            {
                elevatorsInFloor[floor].push_back(elevator);
                floorsAdjacencyList[floor * 10 + elevator].push_back({prevFloor * 10 + elevator, (floor - prevFloor) * elevatorTime[elevator]});
                floorsAdjacencyList[prevFloor * 10 + elevator].push_back({floor * 10 + elevator, (floor - prevFloor) * elevatorTime[elevator]});
                prevFloor = floor;
            }
        }
        for (floor = 0; floor < 100; ++floor)
        {
            elevators = elevatorsInFloor[floor].size();
            for (i = 0; i < elevators; ++i)
                for (j = i + 1; j < elevators; ++j)
                {
                    floorsAdjacencyList[floor * 10 + elevatorsInFloor[floor][i]].push_back({floor * 10 + elevatorsInFloor[floor][j], 60});
                    floorsAdjacencyList[floor * 10 + elevatorsInFloor[floor][j]].push_back({floor * 10 + elevatorsInFloor[floor][i], 60});
                }
        }

        time = searchMinTimeToFloor(floorsAdjacencyList, n, k);

        if (time == -1)
            cout << "IMPOSSIBLE";
        else
            cout << time;
        cout << '\n';
    }
}