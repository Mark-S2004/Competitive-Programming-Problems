#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    short t;
    int n, i;
    string s;
    ull distinctS;

    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        distinctS = s.size();

        for (i = 0; i < n - 1; ++i)
        {
            size_t nextCharIdx = s.find(s[i], i + 1);
            if (nextCharIdx == string::npos)
                nextCharIdx = s.size();
            distinctS += nextCharIdx - i - 1;
        }

        cout << distinctS << '\n';
    }
}