#include <stdio.h>

int main()
{
    int vect[10];
    int vect2[10];

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &vect[i]);
    }
        for (int n = 9; n >= 0; n--)
        {
        printf("%d\n", vect[n]);
        }
return 0;
}