#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short t;
    int n, a;
    ull pairsCount;

    cin >> t;
    while (t--)
    {
        cin >> n;
        map<int, ull> msbFrequency;
        pairsCount = 0;

        while (n--)
        {
            cin >> a;
            msbFrequency[int(__lg(a))]++;
        }
        for (auto frequency : msbFrequency)
            pairsCount += frequency.second * (frequency.second - 1) / 2;

        cout << pairsCount << '\n';
    }
}