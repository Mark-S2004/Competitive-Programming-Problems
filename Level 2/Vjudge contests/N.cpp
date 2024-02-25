#include <bits/stdc++.h>
using namespace std;

int arrangementCounts;
short n, m, a[25], b[25], c[25], teenagerSeat[8];
bool isteenagerSeated[8];

bool isFollowConstraints()
{
    for (int j = 0; j < m; ++j)
    {
        if (c[j] > 0 && abs(teenagerSeat[a[j]] - teenagerSeat[b[j]]) > c[j])
            return false;
        if (c[j] < 0 && abs(teenagerSeat[a[j]] - teenagerSeat[b[j]]) < -c[j])
            return false;
    }
    return true;
}

void seatTeenagers(short i = 0)
{
    if (i == n)
    {
        if (isFollowConstraints())
            ++arrangementCounts;
        return;
    }

    for (int j = 0; j < n; ++j)
    {
        if (!isteenagerSeated[j])
        {
            isteenagerSeated[j] = true;
            teenagerSeat[j] = i;
            seatTeenagers(i + 1);
            isteenagerSeated[j] = false;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while (cin >> n >> m && n)
    {
        for (short i = 0; i < m; ++i)
            cin >> a[i] >> b[i] >> c[i];
        arrangementCounts = 0;
        seatTeenagers();
        cout << arrangementCounts << '\n';
    }
}