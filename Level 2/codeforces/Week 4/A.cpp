#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    float n, x, y;
    cin >> n >> x >> y;
    cout << ceil(n * y / 100.0) - x;
}