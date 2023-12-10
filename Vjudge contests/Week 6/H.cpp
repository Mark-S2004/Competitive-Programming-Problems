#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <string.h>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;
// #define int long long int
// cout<<fixed<<setprecision(10);
#define FIO                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);
#define F first
#define S second
#define lp(i, n) for (int i = 0; i < (int)(n); ++i)
#define lpi(i, j, n) for (int i = (j); i < (int)(n); ++i)

typedef long long int ll;
typedef unsigned long long ull;
const int N = 3e5;
const int mod = 1000000007;
enum dir
{
    d,
    r,
    u,
    l,
    ul,
    dr,
    ur,
    dl
};
int dx[8] = {1, 0, -1, 0, -1, 1, -1, 1};
int dy[8] = {0, 1, 0, -1, -1, 1, 1, -1};

void work()
{
    int n;
    cin >> n;
    vector<int> Line(n);
    for (int i = 0; i < n; i++)
    {
        cin >> Line[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        int height;
        cin >> height;
        int shortG = -1;
        int tall = -1;
        // Lower bound
        int l = 0;
        int r = n - 1;
        int mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (Line[mid] < height)
            {
                shortG = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        // upper bound
        l = 0;
        r = n - 1;
        while (l <= r)
        {
            mid = (l + r) / 2;
            if (Line[mid] > height)
            {
                tall = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        if (shortG == -1)
        {
            cout << "X ";
        }
        else
        {
            cout << Line[shortG] << ' ';
        }
        if (tall == -1)
        {
            cout << "X\n";
        }
        else
        {
            cout << Line[tall] << '\n';
        }
    }
}

int main()
{
    FIO int tc = 1;
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);

    // calcFacAndInv(1000000);
    // cin >> tc;
    while (tc--)
        work();
}
