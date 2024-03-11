#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long

const int MOD = 1e9 + 7;
map<int, int> unionPrimes;

int Egcd(int a, int b, int &x, int &y) // O(log(min(a,b)) and in works with negative a,b
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = Egcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}

int modInv(int a, int m) // o(log(min(a,m)))
{
    int x, y;
    int g = Egcd(a, m, x, y);

    if (g != 1)
        return -1;
    else
        return (x + m) % m;
}

int fastPow(int a, int b, int m) // O(log(b))
{
    if (b == 0)
        return 1;
    int res = fastPow(a, b / 2, m);
    if (b % 2)
        return ((res * res) % m * a % m) % m;
    else
        return (res * res) % m;
}

void factorize(int n)
{
    for (int i = 2; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            int cnt = 0;
            while (n % i == 0)
            {
                ++cnt;
                n /= i;
            }
            unionPrimes[i] = max(unionPrimes[i], cnt);
        }
    }
    if (n > 1)
        unionPrimes[n] = max(unionPrimes[n], 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    ull LCM = 1, bSum = 0;

    cin >> N;
    int A[N];
    while (N--)
    {
        cin >> A[N];
        factorize(A[N]);
    }
    for (pair<int, int> prime : unionPrimes)
    {
        LCM *= fastPow(prime.first, prime.second, MOD);
        LCM %= MOD;
    }
    for (int a : A)
    {
        bSum += (LCM * modInv(a, MOD)) % MOD;
        bSum %= MOD;
    }

    cout << bSum;
}