#include <iostream>
using namespace std;

int main()
{
    unsigned short t, n, a;
    int evenTotal, oddTotal;

    scanf("%hd", &t);
    while (t--)
    {
        evenTotal = 0;
        oddTotal = 0;
        scanf("%hd", &n);
        while (n--)
        {
            scanf("%hd", &a);
            if (a % 2 == 0)
            {
                evenTotal += a;
            }
            else
            {
                oddTotal += a;
            }
        }
        if (evenTotal > oddTotal)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}