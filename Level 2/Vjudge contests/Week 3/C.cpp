#include <bits/stdc++.h>
using namespace std;

int Egcd(int a, int b, long long &x, long long &y) // O(log(min(a,b)) and in works with negative a,b
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    int d = Egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int A, B, C, gcd;
    long long x, y;
    cin >> A >> B >> C;

    gcd = Egcd(-A, -B, x, y);

    if (C % gcd)
    {
        cout << -1;
        return 0;
    }
    cout << x * (C / gcd) << " " << y * (C / gcd);
}