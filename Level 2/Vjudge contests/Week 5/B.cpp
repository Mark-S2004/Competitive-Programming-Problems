#include <bits/stdc++.h>
using namespace std;

bool assumption;

void searchDepthFirst(vector<vector<short>> &adjacencyList, vector<short> &gender, short bug)
{
    for (auto interactionBug : adjacencyList[bug])
    {
        if (gender[interactionBug] != -1)
        {
            if (gender[interactionBug] == gender[bug])
                assumption = false;
            continue;
        }
        gender[interactionBug] = !gender[bug];
        searchDepthFirst(adjacencyList, gender, interactionBug);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, nInteractions, i;
    short nBugs, bug1, bug2;

    cin >> t;
    for (i = 1; i <= t; ++i)
    {
        cin >> nBugs >> nInteractions;
        vector<vector<short>> adjacencyList(nBugs + 1);
        vector<short> gender(nBugs + 1, -1);
        assumption = true;

        while (nInteractions--)
        {
            cin >> bug1 >> bug2;
            adjacencyList[bug1].push_back(bug2);
            adjacencyList[bug2].push_back(bug1);
        }
        for (bug1 = 1; bug1 <= nBugs; ++bug1)
            if (gender[bug1] == -1)
            {
                gender[bug1] = 0;
                searchDepthFirst(adjacencyList, gender, bug1);
            }

        cout << "Scenario #" << i << ":\n";
        cout << (assumption ? "No suspicious bugs found!" : "Suspicious bugs found!") << '\n';
    }
}