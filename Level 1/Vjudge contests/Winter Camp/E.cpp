#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n, m, a, inconvenience;

    cin >> t;
    while (t--)
    {
        priority_queue<int, vector<int>, greater<int>> ai;
        priority_queue<int, vector<int>, greater<int>> temp;
        inconvenience = 0;

        cin >> n >> m;
        while (m--)
        {
            temp = ai;
            cin >> a;
            while (temp.size() && a > temp.top())
            {
                ++inconvenience;
                temp.pop();
            }
            ai.push(a);
        }

        cout << inconvenience << endl;
    }
}