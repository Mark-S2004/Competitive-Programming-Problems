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
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(i);

    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int l, r;
            cin >> l >> r;
            l--;
            r--;
            int last = l;
            while (!st.empty())
            {
                auto it = st.lower_bound(last);
                if (it == st.end() || *it > r)
                    break;
                auto &x = v[*it];
                int sum = 0;
                while (x)
                {
                    sum += x % 10;
                    x /= 10;
                }
                v[*it] = sum;
                int temp = *it;
                if (v[temp] < 10)
                {
                    st.erase(it);
                }
                last = temp + 1;
            }
        }
        else
        {
            int idx;
            cin >> idx;
            idx--;
            cout << v[idx] << '\n';
        }
    }
}

int main()
{
    FIO int tc = 1;
    //    freopen("input.txt","r",stdin);
    //    freopen("output.txt","w",stdout);

    cin >> tc;
    while (tc--)
        work();
}
