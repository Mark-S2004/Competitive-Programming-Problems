#include <bits/stdc++.h>
using namespace std;

short board[9], safeBoard[9], minMoves;

bool safe(short &r, short &c)
{
    for (int col = 1; col < c; ++col)
    {
        if (c - col == abs(safeBoard[col] - r) || r == safeBoard[col])
            return false;
    }
    return true;
}

void moveQueens(short c = 1)
{
    short i;

    if (c == 9)
    {
        short moves = 0;
        for (i = 1; i <= 8; ++i)
        {
            if (board[i] != safeBoard[i])
                ++moves;
        }
        minMoves = min(minMoves, moves);
        return;
    }

    for (i = 1; i <= 8; ++i)
    {
        if (safe(i, c))
        {
            safeBoard[c] = i;
            moveQueens(c + 1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short caseCount = 1;
    while (cin >> board[1])
    {
        minMoves = INT16_MAX;
        for (short i = 2; i <= 8; ++i)
        {
            cin >> board[i];
        }
        moveQueens();
        cout << "Case " << caseCount++ << ": " << minMoves << '\n';
    }
}