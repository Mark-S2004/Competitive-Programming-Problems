#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short n, problem;
    int l, r, x, permutation, sum, hardestProblem, easiestProblem, suitableSets = 0;

    cin >> n >> l >> r >> x;
    int c[n];

    for (problem = 0; problem < n; ++problem)
        cin >> c[problem];
    for (permutation = 1; permutation < (1 << n); ++permutation)
    {
        sum = 0;
        hardestProblem = 0;
        easiestProblem = INT32_MAX;
        for (problem = 0; problem < n; ++problem)
            if (permutation & (1 << problem))
            {
                sum += c[problem];
                hardestProblem = max(hardestProblem, c[problem]);
                easiestProblem = min(easiestProblem, c[problem]);
            }
        if (sum >= l && sum <= r && (hardestProblem - easiestProblem) >= x)
            ++suitableSets;
    }

    cout << suitableSets;
}