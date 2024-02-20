#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned n;
    string recipient;
    unordered_set<string> recipients;
    stack<string> chat;

    cin >> n;
    while (n--)
    {
        cin >> recipient;
        chat.push(recipient);
        recipients.insert(recipient);
    }
    while (recipients.size())
    {
        recipient = chat.top();
        chat.pop();
        if (recipients.find(recipient) != recipients.end())
        {
            cout << recipient << '\n';
            recipients.erase(recipient);
        }
    }
}