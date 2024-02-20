#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, rank = 1, score, scoreSum, SCORE, id, subject;
    priority_queue<int> ranks;

    cin >> n;
    for (id = 1; id <= n; ++id)
    {
        scoreSum = 0;
        for (subject = 0; subject < 4; ++subject)
        {
            cin >> score;
            scoreSum += score;
        }
        if (id == 1)
            SCORE = scoreSum;
        ranks.push(scoreSum);
    }
    while (ranks.size())
    {
        if (SCORE < ranks.top())
        {
            ++rank;
            ranks.pop();
        }
        else
            break;
    }

    cout << rank;
}