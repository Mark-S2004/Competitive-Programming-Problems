#include <iostream>

int main()
{
    unsigned short T;
    unsigned N, i;
    unsigned long long aDiff, bDiff;

    scanf("%hu", &T);
    while (T--)
    {
        aDiff = 0;
        bDiff = 0;
        scanf("%u", &N);
        unsigned a[N], b[N];
        for (i = 0; i < N; i++)
        {
            scanf("%u", &a[i]);
        }
        for (i = 0; i < N; i++)
        {
            scanf("%u", &b[i]);
        }
        for (i = 0; i < N; i++)
        {
            if (a[i] > b[i])
                aDiff += (long long)(a[i] - b[i]);
            else if (a[i] < b[i])
                bDiff += (long long)(b[i] - a[i]);
        }
        if (aDiff == bDiff)
            printf("%llu\n", aDiff);
        else
            printf("-1\n");
    }
}