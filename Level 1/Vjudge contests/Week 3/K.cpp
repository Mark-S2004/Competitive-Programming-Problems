#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short T, N, A, temp, count, i, j, index;
    string ans;
    bool b;

    cin >> T;
    while (T--)
    {
        unsigned short frequency[(int)1e3] = {0}, frequencies[(int)1e3] = {0};
        index = 0;
        cin >> N;
        cin >> temp;
        temp--;
        N--;
        count = 1;
        ans = "YES";
        b = true;
        while (N--)
        {
            cin >> A;
            if (b)
            {
                A--;
                if (A != temp)
                {
                    if (frequency[A])
                    {
                        ans = "NO";
                        b = false;
                    }
                    frequency[temp] = count;
                    frequencies[index++] = temp;
                    count = 1;
                }
                else
                {
                    count++;
                }
                temp = A;
            }
        }
        frequency[A] = count;
        frequencies[index++] = A;
        if (ans == "YES")
        {
            b = false;
            for (i = 0; i < index; i++)
            {
                for (j = i + 1; j < index; j++)
                {
                    if (frequency[frequencies[i]] == frequency[frequencies[j]])
                    {
                        ans = "NO";
                        b = true;
                        break;
                    }
                }
                if (b)
                    break;
            }
        }
        cout << ans << endl;
    }
}