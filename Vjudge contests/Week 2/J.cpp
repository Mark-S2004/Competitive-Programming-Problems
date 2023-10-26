#include <iostream>

int main()
{
    unsigned short t;
    unsigned int i, n, weight, rowMinWeight, colMinWeight;
    long long rowSum, colSum;

    scanf("%hu", &t);
    while (t--)
    {
        scanf("%u", &n);
        rowSum = 0;
        colSum = 0;

        for (i = 0; i < n; i++)
        {
            scanf("%u", &weight);
            rowSum += weight;
            if (i == 0)
                rowMinWeight = weight;
            else if (weight < rowMinWeight)
                rowMinWeight = weight;
        }
        for (i = 0; i < n; i++)
        {
            scanf("%u", &weight);
            colSum += weight;
            if (i == 0)
                colMinWeight = weight;
            else if (weight < colMinWeight)
                colMinWeight = weight;
        }
        rowSum += (long long)n * colMinWeight;
        colSum += (long long)n * rowMinWeight;
        if (rowSum < colSum)
            printf("%lld\n", rowSum);
        else
            printf("%lld\n", colSum);
    }
}