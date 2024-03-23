#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, r, a, b, i, moves;
    int xIncrement[] = {-1, 0, 1, -1, 1, -1, 0, 1}, yIncrement[] = {1, 1, 1, 0, 0, -1, -1, -1};
    pair<int, int> initPos, finalPos, cell, neighbourCell;
    unordered_map<int, unordered_set<int>> allowedCells;
    queue<pair<pair<int, int>, int>> cellsToMoveTo;
    set<pair<int, int>> visitedCells;

    cin >> initPos.first >> initPos.second >> finalPos.first >> finalPos.second;
    cellsToMoveTo.push({initPos, 0});
    visitedCells.insert(initPos);
    cin >> n;
    while (n--)
    {
        cin >> r >> a >> b;
        for (i = a; i <= b; ++i)
            allowedCells[r].insert(i);
    }

    while (cellsToMoveTo.size())
    {
        cell = cellsToMoveTo.front().first;
        moves = cellsToMoveTo.front().second;
        cellsToMoveTo.pop();

        if (cell == finalPos)
        {
            cout << moves;
            return 0;
        }
        for (i = 0; i < 8; ++i)
        {
            neighbourCell.first = cell.first + xIncrement[i];
            neighbourCell.second = cell.second + yIncrement[i];
            if (allowedCells[neighbourCell.first].count(neighbourCell.second) && !visitedCells.count(neighbourCell))
            {
                cellsToMoveTo.push({neighbourCell, moves + 1});
                visitedCells.insert(neighbourCell);
            }
        }
    }

    cout << -1;
}