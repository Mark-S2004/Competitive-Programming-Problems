#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short T, n, a, i, aMax, aMin, maxElementNum;

    scanf("%hu", &T);
    while (T--)
    {
        unsigned short frequency[(int)1e4] = {0};
        aMin = INT16_MAX;
        aMax = 0;
        maxElementNum = 0;
        scanf("%hu", &n);
        for (i = 0; i < n; i++)
        {
            scanf("%hu", &a);
            frequency[--a]++;
            if (a > aMax)
                aMax = a;
            if (a < aMin)
                aMin = a;
        }
        for (i = aMin; i < aMax; i++)
        {
            if (frequency[i] + frequency[i + 1] > maxElementNum)
                maxElementNum = frequency[i] + frequency[i + 1];
        }
        cout << maxElementNum << endl;
    }
}