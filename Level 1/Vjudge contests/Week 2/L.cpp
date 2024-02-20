#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string DNA;
    unsigned frequency[4] = {0}, i = 0;

    getline(cin, DNA);
    while (DNA[i])
    {
        switch (DNA[i])
        {
        case 'A':
            frequency[0]++;
            break;
        case 'C':
            frequency[1]++;
            break;
        case 'G':
            frequency[2]++;
            break;
        case 'T':
            frequency[3]++;
            break;

        default:
            break;
        }
        i++;
    }
    printf("%u", *max_element(frequency, frequency + 4));
}