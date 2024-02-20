#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, i;
    short a;
    vector<short> negative, positive, zero;

    cin >> n;
    while (n--)
    {
        cin >> a;
        if (a > 0)
            positive.push_back(a);
        else if (a < 0)
            negative.push_back(a);
        else
            zero.push_back(a);
    }

    if (!positive.size())
    {
        positive.push_back(negative[negative.size() - 1]);
        negative.pop_back();
        positive.push_back(negative[negative.size() - 1]);
        negative.pop_back();
    }

    if (negative.size() % 2 == 0)
    {
        zero.push_back(negative[negative.size() - 1]);
        negative.pop_back();
    }

    cout << negative.size() << " ";
    for (i = 0; i < negative.size(); i++)
        cout << negative[i] << " ";
    cout << endl;

    cout << positive.size() << " ";
    for (i = 0; i < positive.size(); i++)
        cout << positive[i] << " ";
    cout << endl;

    cout << zero.size() << " ";
    for (i = 0; i < zero.size(); i++)
        cout << zero[i] << " ";
    cout << endl;
}