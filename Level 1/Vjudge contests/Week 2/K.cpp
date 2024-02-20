#include <iostream>

unsigned int reverse(unsigned int n, unsigned int nReversed = 0)
{
    nReversed *= 10;
    nReversed += n % 10;
    n /= 10;
    if (n == 0)
        return nReversed;
    return reverse(n, nReversed);
}

int main()
{
    unsigned short N;
    unsigned int a, b;

    scanf("%hu", &N);
    while (N--)
    {
        scanf("%u %u", &a, &b);
        printf("%u\n", reverse(reverse(a) + reverse(b)));
    }
}