#include <bits/stdc++.h>
using namespace std;

short N, M;

bool isInForest(pair<short, short> &coordinates)
{
    if (coordinates.first >= N || coordinates.first < 0)
        return false;
    if (coordinates.second >= M || coordinates.second < 0)
        return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    short K, x, y, i;
    pair<short, short> tree, neighbour;
    queue<pair<short, short>> nextTree;
    short xIncrement[] = {1, -1, 0, 0}, yIncrement[] = {0, 0, 1, -1};

    cin >> N >> M >> K;
    bool burned[N][M];
    memset(burned, 0, sizeof burned);
    while (K--)
    {
        cin >> x >> y;
        nextTree.push({x - 1, y - 1});
        burned[x - 1][y - 1] = true;
    }

    while (nextTree.size())
    {
        tree = nextTree.front();
        nextTree.pop();
        for (i = 0; i < 4; ++i)
        {
            neighbour.first = tree.first + xIncrement[i];
            neighbour.second = tree.second + yIncrement[i];
            if (isInForest(neighbour) && !burned[neighbour.first][neighbour.second])
            {
                nextTree.push(neighbour);
                burned[neighbour.first][neighbour.second] = true;
            }
        }
    }

    cout << tree.first + 1 << ' ' << tree.second + 1;
}