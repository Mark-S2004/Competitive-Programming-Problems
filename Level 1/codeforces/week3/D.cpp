#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned int T;
    unsigned short x, y, v, t;
    double distance;

    cin >> T;
    while (T--)
    {
        cin >> x >> y >> v >> t;

        distance = sqrt(x * x + y * y);
        if (distance / t > v)
            cout << "NO";
        else
            cout << "YES";
        cout << endl;
    }
}