#include <bits/stdc++.h>
using namespace std;

int main()
{
    unsigned n, i, minElement = INT32_MAX, minDistance = INT32_MAX;

    cin >> n;
    vector<unsigned> a(n), minsIndexes;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        minElement = min(minElement, a[i]);
    }
    for (i = 0; i < n; i++)
    {
        if (a[i] == minElement)
            minsIndexes.push_back(i);
    }
    for (i = 1; i < minsIndexes.size(); i++)
    {
        minDistance = min(minDistance, minsIndexes[i] - minsIndexes[i - 1]);
    }
    cout << minDistance << endl;
}