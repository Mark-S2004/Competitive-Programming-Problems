#include <bits/stdc++.h>
using namespace std;
#define SET_BITS_COUNT(x) __builtin_popcount(x)

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int x;
    cin >> x;
    cout << SET_BITS_COUNT(x);
}