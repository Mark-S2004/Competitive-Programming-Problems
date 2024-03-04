#include <bits/stdc++.h>
using namespace std;

bool canYield23(vector<int> &tuples, short i = 0, int yield = 0)
{
    if (i == 5)
    {
        if (yield == 23)
            return true;
        else
            return false;
    }

    bool possible;
    int nextYield;

    for (int j = 0; j < 3; ++j)
    {
        nextYield = yield;
        switch (j)
        {
        case 0:
            if (!i)
                nextYield = tuples[i];
            else
                nextYield += tuples[i];
            break;

        case 1:
            if (!i)
                nextYield = tuples[i];
            else
                nextYield -= tuples[i];
            break;

        case 2:
            if (!i)
                nextYield = tuples[i];
            else
                nextYield *= tuples[i];
            break;

        default:
            break;
        }

        possible = canYield23(tuples, i + 1, nextYield);
        if (possible)
            return possible;
    }

    return possible;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> a(5);
    short i;
    bool input, possible;
    while (true)
    {
        input = false;
        for (i = 0; i < 5; ++i)
        {
            cin >> a[i];
            if (a[i])
                input = true;
        }
        if (!input)
            break;
        sort(a.begin(), a.end());
        possible = canYield23(a);
        while (!possible && next_permutation(a.begin(), a.end()))
            possible = canYield23(a);
        cout << (possible ? "Possible" : "Impossible") << '\n';
    }
}