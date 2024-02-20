#include <iostream>

using namespace std;

int main()
{
    short w;

    scanf("%hd", &w);
    if (w % 2 == 0 && w != 2)
    {
        printf("YES\n");
        return 0;
    }
    printf("NO\n");
    return 0;
}