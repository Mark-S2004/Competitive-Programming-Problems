#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n;
    unsigned box;
    vector<unordered_set<unsigned>> visibleBoxes;
    vector<unordered_set<unsigned>>::iterator it;

    cin >> n;
    while (n--)
    {
        cin >> box;
        for (it = visibleBoxes.begin(); it != visibleBoxes.end(); it++)
        {
            if (it->find(box) == it->end())
            {
                it->insert(box);
                box = 0;
                break;
            }
        }
        if (box)
        {
            unordered_set<unsigned> newSet;
            newSet.insert(box);
            visibleBoxes.push_back(newSet);
        }
    }

    cout << visibleBoxes.size();
}