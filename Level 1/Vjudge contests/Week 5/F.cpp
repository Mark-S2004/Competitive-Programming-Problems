#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned short n, m;
    string name, ip;
    unordered_map<string, string> servers;

    cin >> n >> m;
    while (n--)
    {
        cin >> name >> ip;
        servers[ip] = name;
    }

    while (m--)
    {
        cin >> name >> ip;
        cout << name << ' ' << ip << " #" << servers[ip.erase(ip.length() - 1)] << '\n';
    }
}