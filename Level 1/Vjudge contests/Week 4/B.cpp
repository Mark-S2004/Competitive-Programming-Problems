#include <iostream>
#include <queue>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    queue<int> q;

    cin >> T;
    while (T--)
    {
        int query;
        cin >> query;
        if (query == 1)
        {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (query == 2)
        {
            if (!q.empty())
                q.pop();
        }
        else
        {
            if (q.empty())
                cout << "Empty!\n";
            else
                cout << q.front() << "\n";
        }
    }
}