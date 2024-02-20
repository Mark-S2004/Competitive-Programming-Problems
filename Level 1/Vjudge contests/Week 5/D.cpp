#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string str;
    bool correct;

    cin >> n;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (n--)
    {
        correct = true;
        stack<bool> open;

        getline(cin, str);
        for (char c : str)
        {
            switch (c)
            {
            case '(':
                open.push(false);
                break;

            case ')':
                if (open.size() && !open.top())
                    open.pop();
                else
                    correct = false;
                break;

            case '[':
                open.push(true);
                break;

            default:
                if (open.size() && open.top())
                    open.pop();
                else
                    correct = false;
                break;
            }
            if (!correct)
                break;
        }
        if (correct && open.empty())
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}