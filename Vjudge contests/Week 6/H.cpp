#include <bits/stdc++.h>
using namespace std;

#define longestShorterl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short N, Q, i;

    cin >> N;
    long long int ladyChimps[N], Luchu;
    for (i = 0; i < N; ++i)
        cin >> ladyChimps[i];

    cin >> Q;
    while (Q--)
    {
        cin >> Luchu;
        short shortestLonger = 0, md, longestShorter = N - 1;

        while (shortestLonger <= longestShorter)
        {
            md = (shortestLonger + longestShorter) / 2;
            if (ladyChimps[md] < Luchu)
                shortestLonger = md + 1;
            else if (ladyChimps[md] > Luchu)
                longestShorter = md - 1;
            else
            {
                longestShorter = md - 1;
                shortestLonger = md + 1;
                break;
            }
        }

        if (longestShorter < 0)
            cout << "X ";
        else
            cout << ladyChimps[longestShorter] << ' ';
        if (shortestLonger >= N)
            cout << "X\n";
        else
            cout << ladyChimps[shortestLonger] << endl;
    }
}