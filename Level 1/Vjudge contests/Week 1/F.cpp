#include <iostream>
using namespace std;

int main()
{
    short N;

    scanf("%hd", &N);
    printf("%hd%hd", (N % 100) / 10, N % 10);
}