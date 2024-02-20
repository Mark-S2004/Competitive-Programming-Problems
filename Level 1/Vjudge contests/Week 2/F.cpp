#include <iostream>

int main()
{
    short t, n, x, y;
    char direction;
    bool candyPass;

    scanf("%hd", &t);
    while (t--)
    {
        x = 0;
        y = 0;
        candyPass = false;
        scanf("%hd%*c", &n);
        while (n--)
        {
            scanf("%c", &direction);
            switch (direction)
            {
            case 'U':
                y += 1;
                break;
            case 'D':
                y -= 1;
                break;
            case 'R':
                x += 1;
                break;
            case 'L':
                x -= 1;
                break;

            default:
                break;
            }
            if (x == 1 && y == 1)
                candyPass = true;
        }
        if (candyPass)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }
}