#include <stdio.h>

int main()
{

    int n, x0, x1;
    int xn = 0;
    
    printf("digite os numeros: ");
    scanf("%d %d %d",&n, &x0, &x1);

    printf("X0: %d\n", x0);
    printf("X1: %d\n", x1);
    
    int xn2 = x0;
    int xn1 = x1;

        for (int i=2; i <= n; i++)
        {
            xn = 4*xn1 - 2*xn2;
            printf("X%d: %d\n", i,xn);
            xn2 = xn1;
            xn1 = xn;
        };
    return 0;   
}