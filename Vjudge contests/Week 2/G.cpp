#include <iostream>

int main()
{
    short t, i, j, totalPoints;
    char target;

    scanf("%hd%c", &t, &target);
    while (t--)
    {
        totalPoints = 0;
        for (i = 1; i <= 10; i++)
        {
            for (j = 1; j <= 10; j++)
            {
                scanf("%c", &target);
                if (target == 'X')
                {
                    if (i == 1 || i == 10 || j == 1 || j == 10)
                    {
                        totalPoints += 1;
                    }
                    else if (i == 2 || i == 9 || j == 2 || j == 9)
                    {
                        totalPoints += 2;
                    }
                    else if (i == 3 || i == 8 || j == 3 || j == 8)
                    {
                        totalPoints += 3;
                    }
                    else if (i == 4 || i == 7 || j == 4 || j == 7)
                    {
                        totalPoints += 4;
                    }
                    else
                    {
                        totalPoints += 5;
                    }
                }
            }
            scanf("%c", &target);
        }
        printf("%hd\n", totalPoints);
    }
}