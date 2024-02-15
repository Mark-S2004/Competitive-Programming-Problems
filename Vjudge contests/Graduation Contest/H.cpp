using namespace std;
#include <bits/stdc++.h>

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, i;
    char c;
    list<int> a;
    a.push_back(0);
    list<int>::iterator it = a.begin();

    cin >> n;
    for (i = 1; i <= n; ++i)
    {
        cin >> c;
        if (c == 'L')
            if (it == a.begin())
            {
                a.push_front(i);
                it = a.begin();
            }
            else
            {
                a.insert(it, i);
                it--;
            }
        else if (*it == a.back())
        {
            a.push_back(i);
            it++;
        }
        else
        {
            a.insert(++it, i);
            --it;
        }
    }

    for (i = 0; i <= n; ++i)
    {
        cout << a.front() << " ";
        a.pop_front();
    }
}