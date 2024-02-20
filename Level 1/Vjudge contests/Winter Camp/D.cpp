#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, x, k, loc, step, increment;

    cin >> t;
    while (t--)
    {
        cin >> x >> k;

        vector<int> steps;
        loc = 0;
        step = x;
        increment = 0;
        while (x != loc)
        {
            if (step % k != 0)
            {
                loc += step;
                steps.push_back(step);
                step = x - loc;
            }
            else
            {
                if (increment >= 0)
                    ++increment;
                step -= increment;
                increment *= -1;
            }
        }

        cout << steps.size() << endl;
        for (int i = 0; i < steps.size(); ++i)
            cout << steps[i] << " ";
        cout << endl;
    }
}