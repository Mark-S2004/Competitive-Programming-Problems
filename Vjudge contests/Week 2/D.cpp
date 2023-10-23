#include <iostream>

int main()
{
    short t, n, n2, a, oddCount;

    scanf("%hd", &t);
    while (t--)
    {
        oddCount = 0;
        scanf("%hd", &n);
        n2 = n * 2;
        while (n2--)
        {
            scanf("%hd", &a);
            if (a % 2 != 1)
                oddCount++;
        }
        if (oddCount == n)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
}