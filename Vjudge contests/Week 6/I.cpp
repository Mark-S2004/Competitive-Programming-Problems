#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t, type, num;
    unsigned n, q, i, l, r, x;
    set<unsigned>::iterator it;

    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        unsigned a[n];
        set<unsigned> twoDigitNumIndex;

        for (i = 0; i < n; ++i)
        {
            cin >> a[i];
            if (a[i] > 9)
                twoDigitNumIndex.insert(i);
        }
        while (q--)
        {
            cin >> type;
            switch (type)
            {
            case 1:
                cin >> l >> r;
                --l;
                --r;
                for (it = twoDigitNumIndex.lower_bound(l); it != twoDigitNumIndex.lower_bound(r + 1); it = twoDigitNumIndex.lower_bound(l))
                {
                    num = a[*it];
                    a[*it] = 0;
                    while (num)
                    {
                        a[*it] += num % 10;
                        num /= 10;
                    }
                    if (a[*it] < 10)
                    {
                        l = *it;
                        twoDigitNumIndex.erase(it);
                    }
                    ++l;
                }
                break;

            case 2:
                cin >> x;
                cout << a[--x] << endl;
                break;

            default:
                break;
            }
        }
    }
}