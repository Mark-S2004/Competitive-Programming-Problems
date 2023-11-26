#include <bits/stdc++.h>
using namespace std;

/*
void output_situation(const int &truck, stack<int> st, const int &counter)
{
    cout << truck << "   " << counter - 1 << '\n';
    unsigned n = st.size();
    while (n--)
    {
        cout << "  " << st.top() << '\n';
        st.pop();
    }
}
*/

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, truck, counter = 1;
    stack<int> sideStreet;
    cin >> n;
    if (!n)
        return 0;
    while (n--)
    {
        cin >> truck;
        // output_situation(truck, sideStreet, counter);
        if (truck != counter)
        {
            if (sideStreet.size() && (sideStreet.top() == counter))
                while (sideStreet.size() && (sideStreet.top() == counter))
                {
                    sideStreet.pop();
                    counter++;
                    // output_situation(truck, sideStreet, counter);
                }
            else
                sideStreet.push(truck);
        }
        else
            counter++;
    }
    cin >> truck;
    while (sideStreet.size() && (sideStreet.top() == counter))
    {
        sideStreet.pop();
        counter++;
        // output_situation(truck, sideStreet, counter);
    }
    if (sideStreet.empty())
        cout << "yes" << '\n';
    else
        cout << "no" << '\n';
}