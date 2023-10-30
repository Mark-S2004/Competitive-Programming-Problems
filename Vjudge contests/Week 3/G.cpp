#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    unsigned short nCount = 0, iCount = 0, eCount = 0, tCount = 0;

    getline(cin, s);
    for (char c : s)
    {
        if (c == 'n')
            nCount++;
        else if (c == 'i')
            iCount++;
        else if (c == 'e')
            eCount++;
        else if (c == 't')
            tCount++;
    }
    if (nCount % 2 == 0)
        nCount = (nCount - 2) / 2;
    else
        nCount = (nCount - 1) / 2;
    cout << min(min((int)nCount, (int)iCount), min(eCount / 3, (int)tCount)) << endl;
}