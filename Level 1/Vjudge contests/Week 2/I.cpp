#include <iostream>

int main()
{
    unsigned int n, count4 = 0, count3 = 0, count2 = 0, count1 = 0;
    short s;

    scanf("%d", &n);
    while (n--)
    {
        scanf("%hd", &s);
        if (s == 4)
            count4++;
        else if (s == 3)
            count3++;
        else if (s == 2)
            count2++;
        else
            count1++;
    }
    if (count1 > count3)
        count1 -= count3;
    else
        count1 = 0;
    if (count1 > 2 && count2 % 2)
        count1 -= 2;
    else if (count2 % 2)
        count1 = 0;
    printf("%d", count4 + count3 + count2 / 2 + count2 % 2 + (count1 + 4 - 1) / 4);
}