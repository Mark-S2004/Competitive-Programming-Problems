#include <bits/stdc++.h>
using namespace std;

void printAllBitStrings(int bitLength, int hammingDistance, string bitString)
{
    if (int(bitString.size()) == bitLength && hammingDistance == 0)
    {
        cout << bitString << '\n';
        return;
    }
    if (int(bitString.size()) > bitLength || hammingDistance < 0)
        return;
    printAllBitStrings(bitLength, hammingDistance, bitString + '0');
    printAllBitStrings(bitLength, hammingDistance - 1, bitString + '1');
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, bitLength, hammingDistance;
    string emptyLine;

    cin >> t;
    while (t--)
    {
        getline(cin, emptyLine);
        cin >> bitLength >> hammingDistance;
        printAllBitStrings(bitLength, hammingDistance, "");
        if (t)
            cout << '\n';
    }
}