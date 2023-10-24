#include <iostream>

int main()
{
    short nQAQ = 0, i, j, k;
    char str[101];

    scanf("%s", str);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != 'Q')
            continue;
        for (j = i + 1; str[j] != '\0'; j++)
        {
            if (str[j] != 'A')
                continue;
            for (k = j + 1; str[k] != '\0'; k++)
            {
                if (str[k] != 'Q')
                    continue;
                nQAQ++;
            }
        }
    }
    printf("%hd", nQAQ);
}