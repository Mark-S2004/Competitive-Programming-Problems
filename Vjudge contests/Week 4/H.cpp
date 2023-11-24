#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned Q;
    unsigned short N;
    deque<unsigned short> Nq;
    bool reversed = false;
    string query;

    cin >> Q;
    while (Q--)
    {
        cin >> query;
        if (query == "front")
        {
            if (Nq.size())
            {
                if (reversed)
                {
                    cout << Nq.back() << endl;
                    Nq.pop_back();
                }
                else
                {
                    cout << Nq.front() << endl;
                    Nq.pop_front();
                }
            }
            else
                cout << "No job for Ada?" << endl;
        }
        else if (query == "back")
        {
            if (Nq.size())
            {
                if (reversed)
                {
                    cout << Nq.front() << endl;
                    Nq.pop_front();
                }
                else
                {
                    cout << Nq.back() << endl;
                    Nq.pop_back();
                }
            }
            else
                cout << "No job for Ada?" << endl;
        }
        else if (query == "reverse")
            reversed = !reversed;
        else if (query == "push_back")
        {
            cin >> N;
            if (reversed)
                Nq.push_front(N);
            else
                Nq.push_back(N);
        }
        else if (query == "toFront")
        {
            cin >> N;
            if (reversed)
                Nq.push_back(N);
            else
                Nq.push_front(N);
        }
    }
}