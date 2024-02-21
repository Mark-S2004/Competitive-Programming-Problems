#include <bits/stdc++.h>
using namespace std;

bool isSolutionPossible(vector<unsigned short> bars, unsigned short desiredLength, unsigned short i, unsigned short currentLength)
{
    bool solutionReached;

    if (currentLength == desiredLength)
        return true;
    if (i == bars.size() || currentLength > desiredLength)
        return false;

    solutionReached = isSolutionPossible(bars, desiredLength, i + 1, currentLength);
    if (!solutionReached)
        solutionReached = isSolutionPossible(bars, desiredLength, i + 1, currentLength + bars[i]);

    return solutionReached;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t, n, p, barLength;

    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        vector<unsigned short> bars;
        while (p--)
        {
            cin >> barLength;
            bars.push_back(barLength);
        }
        cout << (isSolutionPossible(bars, n, 0, 0) ? "YES" : "NO") << '\n';
    }
}