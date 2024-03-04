#include <bits/stdc++.h>
using namespace std;

long long leastBiggerSuperLucky(int n, short i = 1, short i4 = 0, short i7 = 0, long long superLucky = 0)
{
    if (superLucky >= n && i4 == i && i7 == i)
        return superLucky;

    long long lucky = 0;
    if (i4 < i)
        lucky = leastBiggerSuperLucky(n, i, i4 + 1, i7, superLucky * 10 + 4);
    if (i7 < i && !lucky)
        lucky = leastBiggerSuperLucky(n, i, i4, i7 + 1, superLucky * 10 + 7);
    if (!i4 && !i7 && !lucky)
        lucky = leastBiggerSuperLucky(n, i + 1);

    return lucky;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, digitsCount = 1, temp;
    cin >> n;
    temp = n;
    while (temp /= 10)
        ++digitsCount;
    if (digitsCount % 2 == 1)
        ++digitsCount;
    cout << leastBiggerSuperLucky(n, digitsCount / 2);
}