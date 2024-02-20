#include <iostream>
using namespace std;

int main()
{
    unsigned short t;
    short rating;

    scanf("%hd", &t);
    while (t--)
    {
        scanf("%hd", &rating);
        printf("Division ");
        if (rating >= 1900)
        {
            printf("1");
        }
        else if (rating >= 1600)
        {
            printf("2");
        }
        else if (rating >= 1400)
        {
            printf("3");
        }
        else
        {
            printf("4");
        }
        printf("\n");
    }
}