#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short T, n, m, i;
    char si;
    unsigned int maxSimilarity;

    cin >> T;
    while (T--)
    {
        maxSimilarity = 0;
        cin >> n >> m;
        unsigned short frequency[50][sizeof(char)] = {0};
        while (n--)
        {
            for (i = 0; i < m; i++)
            {
                cin >> si;
                frequency[i][(int)si]++;
                printf("m=%hu intSi=%d si=%c f=%hu\n", i, (int)si, si, frequency[i][(int)si]);
            }
        }
        for (i = 0; i < m; i++)
        {
            cout << *max_element(frequency[i], frequency[i] + sizeof(char)) << endl;
            maxSimilarity += *max_element(frequency[i], frequency[i] + sizeof(char));
        }
        cout << maxSimilarity << endl;
    }
}