#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short t, n, i, j;
    unordered_map<string, short>::iterator it;

    cin >> t;
    while (t--)
    {
        cin >> n;
        string player[3][n];
        unsigned short scores[3] = {0};
        unordered_map<string, short> wordFrequency;

        for (i = 0; i < 3; i++)
            for (j = 0; j < n; j++)
            {
                cin >> player[i][j];
                it = wordFrequency.find(player[i][j]);
                if (it == wordFrequency.end())
                    wordFrequency[player[i][j]] = 1;
                else
                    it->second++;
            }
        for (i = 0; i < 3; i++)
            for (string word : player[i])
            {
                switch (wordFrequency[word])
                {
                case 1:
                    scores[i] += 3;
                    break;

                case 2:
                    scores[i] += 1;
                    break;

                default:
                    break;
                }
            }

        cout << scores[0] << " " << scores[1] << " " << scores[2] << '\n';
    }
}