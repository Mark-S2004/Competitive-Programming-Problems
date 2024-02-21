#include <bits/stdc++.h>
using namespace std;

unordered_map<int, long long> cycleLengths;

long long collatzConjecture(int n)
{
    long long cycleLength;

    if (cycleLengths.count(n))
        return cycleLengths[n];
    if (n == 1)
        return 1;
    if (n % 2 == 0)
        cycleLength = collatzConjecture(n / 2) + 1;
    else
        cycleLength = collatzConjecture(3 * n + 1) + 1;
    cycleLengths[n] = cycleLength;
    return cycleLength;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    long long maxCycleLength;
    int I, J, i, j;
    string inputLine;

    while (getline(cin, inputLine), !(inputLine.empty()))
    {
        maxCycleLength = 0;
        sscanf(inputLine.c_str(), "%d %d", &I, &J);
        i = min(I, J);
        j = max(I, J);

        for (i; i <= j; ++i)
            maxCycleLength = max(maxCycleLength, collatzConjecture(i));

        cout << I << " " << J << " " << maxCycleLength << "\n";
    }
}