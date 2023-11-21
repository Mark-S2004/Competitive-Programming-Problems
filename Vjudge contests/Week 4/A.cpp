#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, i;

    cin >> N;
    vector<int> v(N);
    for (i = 0; i < N; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    for (i = 0; i < N; i++)
    {
        cout << v[i] << " ";
    }
}