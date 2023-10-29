#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t, n, a, i;
    bool found;

    scanf("%hu", &t);
    while (t--)
    {
        unsigned short aSubArr[3] = {0}, aIndex[3] = {1, 2, 3};
        found = false;
        i = 4;
        scanf("%hu", &n);
        scanf("%hu", &a);
        aSubArr[0] = a;
        scanf("%hu", &a);
        aSubArr[1] = a;
        scanf("%hu", &a);
        aSubArr[2] = a;
        if (aSubArr[0] == aSubArr[1] && aSubArr[1] == aSubArr[2])
        {
            for (i; i <= n; i++)
            {
                scanf("%hu", &a);
                if (!found)
                {
                    aSubArr[0] = aSubArr[1];
                    aIndex[0] = aIndex[1];
                    aSubArr[1] = aSubArr[2];
                    aIndex[1] = aIndex[2];
                    aSubArr[2] = a;
                    aIndex[2] = i;
                    if (aSubArr[0] == aSubArr[1] && aSubArr[1] == aSubArr[2])
                        continue;
                    else if (aSubArr[0] == aSubArr[1])
                        cout << aIndex[2] << endl;
                    else if (aSubArr[1] == aSubArr[2])
                        cout << aIndex[0] << endl;
                    else
                        cout << aIndex[1] << endl;
                    found = true;
                }
            }
        }
        else if (aSubArr[0] == aSubArr[1])
            cout << aIndex[2] << endl;
        else if (aSubArr[1] == aSubArr[2])
            cout << aIndex[0] << endl;
        else
            cout << aIndex[1] << endl;
        for (i; i <= n; i++)
            scanf("%hu", &a);
    }
}