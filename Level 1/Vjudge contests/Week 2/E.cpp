#include <iostream>

int main()
{
    short t, n, a, smallest;
    int product;

    scanf("%hd", &t);
    while (t--)
    {
        scanf("%hd\n%hd", &n, &a);
        if (a)
        {
            product = a;
        }
        else
        {
            product = 1;
        }
        smallest = a;
        while (--n)
        {
            scanf("%hd", &a);
            if (a)
            {
                product *= a;
            }
            else if (a == smallest)
            {
                product = 0;
            }
            if (a < smallest)
                smallest = a;
        }
        if (product && smallest)
            product /= smallest;
        product *= ++smallest;
        printf("%d\n", product);
    }
}