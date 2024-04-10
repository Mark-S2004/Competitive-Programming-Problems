#include <bits/stdc++.h>
using namespace std;
#define ll long long

short findExitMiceCount(vector<vector<pair<short, int>>> &mazeAdjacencyList, int T, short E)
{
    int time;
    short cell, exitMiceCount = 0;
    vector<int> cellsDurations(mazeAdjacencyList.size(), INT32_MAX);
    cellsDurations[E] = 0;
    priority_queue<pair<int, short>, vector<pair<int, short>>, greater<pair<int, short>>> nextCellToVisit;
    nextCellToVisit.push({0, E});
    while (nextCellToVisit.size())
    {
        time = nextCellToVisit.top().first;
        cell = nextCellToVisit.top().second;
        nextCellToVisit.pop();
        if (time != cellsDurations[cell])
            continue;
        for (auto neighbour : mazeAdjacencyList[cell])
            if (cellsDurations[neighbour.first] > time + neighbour.second)
            {
                cellsDurations[neighbour.first] = time + neighbour.second;
                nextCellToVisit.push({cellsDurations[neighbour.first], neighbour.first});
            }
    }
    for (int duration : cellsDurations)
        if (duration <= T)
            ++exitMiceCount;
    return exitMiceCount;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, T, M, time;
    short N, E, a, b;
    string blank;

    cin >> t;
    while (t--)
    {
        getline(cin, blank);
        cin >> N >> E >> T >> M;
        vector<vector<pair<short, int>>> mazeAdjacencyList(N + 1);
        while (M--)
        {
            cin >> a >> b >> time;
            mazeAdjacencyList[b].push_back({a, time});
        }

        cout << findExitMiceCount(mazeAdjacencyList, T, E) << "\n";
        if (t)
            cout << '\n';
    }
}