#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string input, token;
    unsigned page;
    set<unsigned> pages;
    set<unsigned>::iterator l, r, temp;

    cin >> input;
    stringstream check1(input);
    while (getline(check1, token, ','))
    {
        page = stoul(token);
        pages.insert(page);
    }
    for (l = pages.begin(); l != pages.end(); ++l)
    {
        r = l;
        ++r;
        if (*l + 1 == *r)
        {
            for (r; r != pages.end(); ++r)
            {
                temp = r;
                ++temp;
                if (*r + 1 != *temp)
                {
                    cout << *l << '-' << *r;
                    break;
                }
            }
            l = r;
        }
        else
            cout << *l;
        temp = l;
        ++temp;
        if (r != pages.end() && temp != pages.end())
            cout << ',';
    }
}