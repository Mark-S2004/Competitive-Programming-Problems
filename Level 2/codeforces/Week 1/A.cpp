#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, H, monster, i;

    cin >> N >> H;
    for (i = 0; i < N; ++i)
    {
        cin >> monster;
        if (H >= monster)
            H += monster;
        else
        {
            cout << "NAO";
            return 0;
        }
    }

    cout << "SIM";
}