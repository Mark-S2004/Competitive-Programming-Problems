#include <iostream>

int main()
{
    unsigned T;
    short X, Y;

    scanf("%u", &T);
    while (T--)
    {
        scanf("%hd %hd", &X, &Y);
        printf("0 %hd %hd\n", Y, 3 * X - Y);
    }
}