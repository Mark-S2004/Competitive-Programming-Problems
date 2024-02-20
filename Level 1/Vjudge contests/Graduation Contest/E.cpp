using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int days, people, a, b, i, bPrev = 0, duplicates = 1, A;
    bool done0 = false, done1 = false;

    cin >> days >> people;
    for (i = 0; i < people; ++i)
    {
        cin >> a >> b;
        if (!done1)
            if (a > bPrev + 1)
            {
                cout << bPrev + 1 << " 0";
                done0 = true;
            }
        if (!done0)
            if (a == bPrev)
            {
                if (!done1)
                    A = a;
                if (a == A)
                    ++duplicates;
                done1 = true;
            }
        bPrev = b;
    }
    if (done1)
        cout << A << " " << duplicates;
    else if (!done0)
        cout << "OK";
}