#include <bits/stdc++.h>
using namespace std;

int N, tracksCount;

pair<int, vector<int>> fillTape(int *CD, vector<int> tracks, int i = 0, int sum = 0)
{
    if (sum == N || i == tracksCount)
        return {sum, tracks};

    pair<int, vector<int>> fill, noFill;
    vector<int> tracksFill = tracks;

    if (sum + CD[i] <= N)
    {
        tracksFill.push_back(CD[i]);
        fill = fillTape(CD, tracksFill, i + 1, sum + CD[i]);
    }
    noFill = fillTape(CD, tracks, i + 1, sum);

    if (fill.first == noFill.first)
    {
        if (fill.second.size() >= noFill.second.size())
        {
            return fill;
        }
        else
            return noFill;
    }

    return max(fill, noFill);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i;
    pair<int, vector<int>> tape;
    while (cin >> N)
    {
        cin >> tracksCount;
        int CD[tracksCount];
        vector<int> tracks;
        for (i = 0; i < tracksCount; ++i)
            cin >> CD[i];
        tape = fillTape(CD, tracks);
        for (int track : tape.second)
        {
            cout << track << " ";
        }
        cout << "sum:" << tape.first << '\n';
    }
}