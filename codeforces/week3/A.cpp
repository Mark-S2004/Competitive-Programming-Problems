#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, ansFrequency[5] = {0};
    char ans;

    cin >> n;
    while (n--)
    {
        cin >> ans;
        switch (ans)
        {
        case 'a':
            ansFrequency[0]++;
            break;

        case 'b':
            ansFrequency[1]++;
            break;

        case 'c':
            ansFrequency[2]++;
            break;

        case 'd':
            ansFrequency[3]++;
            break;

        case 'e':
            ansFrequency[4]++;
            break;

        default:
            break;
        }
    }
    cout << *min_element(ansFrequency, ansFrequency + 5) << ' ' << *max_element(ansFrequency, ansFrequency + 5) << endl;
}