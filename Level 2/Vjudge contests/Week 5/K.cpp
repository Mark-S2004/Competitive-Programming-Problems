#include <bits/stdc++.h>
using namespace std;

pair<short, int> getTapDiameter(vector<vector<pair<short, int>>> &adjacencyList, short house)
{
    pair<short, int> tapDiameter = {house, INT32_MAX};

    for (pair<short, int> neighbour : adjacencyList[house])
    {
        tapDiameter = getTapDiameter(adjacencyList, neighbour.first);
        tapDiameter.second = min(tapDiameter.second, neighbour.second);
    }

    return tapDiameter;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, p, a, b, house;
    int d;
    pair<short, int> tapDiameter;
    vector<pair<int, pair<short, short>>> tankTapPairs;

    cin >> n >> p;
    vector<vector<pair<short, int>>> adjacencyList(n + 1);
    vector<bool> tanks(n + 1, true);
    while (p--)
    {
        cin >> a >> b >> d;
        adjacencyList[a].push_back({b, d});
        tanks[b] = false;
    }

    for (house = 1; house <= n; ++house)
    {
        if (tanks[house] && adjacencyList[house].size())
        {
            tapDiameter = getTapDiameter(adjacencyList, house);
            tankTapPairs.push_back({tapDiameter.second, {house, tapDiameter.first}});
        }
    }

    cout << tankTapPairs.size() << '\n';
    for (auto tankTapPair : tankTapPairs)
        cout << tankTapPair.second.first << ' ' << tankTapPair.second.second << ' ' << tankTapPair.first << '\n';
}