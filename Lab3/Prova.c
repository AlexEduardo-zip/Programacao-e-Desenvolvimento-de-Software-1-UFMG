#include <stdio.h>

int main()
{
    int x;
    int a = 3; 
    int b =8;
    x = (a & 1) | (b | 2);
    printf("%d \n", x);
    printf("%d", b);
    return 0;
}