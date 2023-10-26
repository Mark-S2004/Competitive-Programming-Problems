#include <iostream>

int main()
{
    unsigned n, i;

    scanf("%u", &n);
    if (1 < n && n <= 3)
    {
        printf("NO SOLUTION");
        return 0;
    }
    for (i = 2; i <= n; i += 2)
    {
        printf("%u ", i);
    }
    for (i = 1; i <= n; i += 2)
    {
        printf("%u ", i);
    }
}