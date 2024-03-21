#include <bits/stdc++.h>
using namespace std;

bool isInBoard(pair<short, short> square)
{
    if (square.first < 0 || square.first >= 8)
        return false;
    if (square.second < 0 || square.second >= 8)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string knightSquare, destinationSquare;
    unordered_map<char, short> COLUMNS = {
        {'a', 0},
        {'b', 1},
        {'c', 2},
        {'d', 3},
        {'e', 4},
        {'f', 5},
        {'g', 6},
        {'h', 7},
    };
    short rowIncrement[] = {1, 1, 2, 2, -1, -1, -2, -2}, colIncrement[] = {2, -2, 1, -1, 2, -2, 1, -1}, move;
    int visited[8][8];

    while (cin >> knightSquare >> destinationSquare)
    {
        if (knightSquare == destinationSquare)
        {
            cout << "To get from " << knightSquare << " to " << destinationSquare << " takes " << 0 << " knight moves.\n";
            continue;
        }
        memset(visited, -1, sizeof visited);
        queue<pair<short, short>> squaresToVisit;
        squaresToVisit.push({knightSquare[1] - '1', COLUMNS[knightSquare[0]]});
        visited[knightSquare[1] - '1'][COLUMNS[knightSquare[0]]] = 0;
        pair<short, short> square, nextSquare;
        bool arrived = false;

        while (squaresToVisit.size())
        {
            square = squaresToVisit.front();
            squaresToVisit.pop();
            for (move = 0; move < 8; ++move)
            {
                nextSquare.first = square.first + rowIncrement[move];
                nextSquare.second = square.second + colIncrement[move];
                if (isInBoard(nextSquare) && visited[nextSquare.first][nextSquare.second] == -1)
                {
                    if (nextSquare.first == destinationSquare[1] - '1' && nextSquare.second == COLUMNS[destinationSquare[0]])
                    {
                        cout << "To get from " << knightSquare << " to " << destinationSquare << " takes " << visited[square.first][square.second] + 1 << " knight moves.\n";
                        arrived = true;
                        break;
                    }
                    squaresToVisit.push(nextSquare);
                    visited[nextSquare.first][nextSquare.second] = visited[square.first][square.second] + 1;
                }
            }
            if (arrived)
                break;
        }
    }
}