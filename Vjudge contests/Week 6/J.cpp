#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <set>
#include <map>
#include <cctype>
#include <algorithm>

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

int n, k;

bool tmam(int v)
{
    int x = v;
    while (v > 0)
    {
        v /= k;
        x += v;
    }
    if (x >= n)
    {
        return true;
    }
    return false;
}
void work()
{

    cin >> n >> k;
    int l = k;
    int r = n;
    int mid;
    int ans = n;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (tmam(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans;
}

int main()
{
    FIO int tc = 1;
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);

    // cin >> tc;
    while (tc--)
        work();
}
