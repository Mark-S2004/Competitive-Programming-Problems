#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned int a, b, minVal;

    cin >> a >> b;
    minVal = min(a, b);

    cout << factorial(minVal);
}