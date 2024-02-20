#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n, ai, i;
    vector<char> s;

    cin >> n;
    deque<unsigned> a;
    while (n--)
    {
        cin >> ai;
        a.push_back(ai);
    }
    ai = 0;
    while (a.size())
    {
        if (ai < a.front() && ai < a.back())
        {
            if (a.front() < a.back())
            {
                s.push_back('L');
                ai = a.front();
                a.pop_front();
            }
            else
            {
                s.push_back('R');
                ai = a.back();
                a.pop_back();
            }
        }
        else if (ai < a.front())
        {
            s.push_back('L');
            ai = a.front();
            a.pop_front();
        }
        else if (ai < a.back())
        {
            s.push_back('R');
            ai = a.back();
            a.pop_back();
        }
        else
            break;
    }
    cout << s.size() << endl;
    for (i = 0; i < s.size(); i++)
        cout << s[i];
    cout << endl;
}