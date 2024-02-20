#include <bits/stdc++.h>
using namespace std;

void passTrucks(const int truck, int &counter, stack<int> &sideStreet)
{
    if (truck == counter)
    {
        counter++;
        return;
    }
    if (sideStreet.size() && (sideStreet.top() == counter))
    {
        sideStreet.pop();
        counter++;
        passTrucks(truck, counter, sideStreet);
    }
    else
        sideStreet.push(truck);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, truck, counter;
    while (cin >> n, n)
    {
        counter = 1;
        stack<int> sideStreet;
        while (n--)
        {
            cin >> truck;
            passTrucks(truck, counter, sideStreet);
        }
        while (sideStreet.size() && (sideStreet.top() == counter))
        {
            sideStreet.pop();
            counter++;
        }
        if (sideStreet.empty())
            cout << "yes" << '\n';
        else
            cout << "no" << '\n';
    }
}