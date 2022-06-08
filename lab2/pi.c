#include <stdio.h>
#include <math.h>

int main()
{
    double num;
    double pi=0;
    int i=0;
    int somador=1;
        
    printf("insira o numero: ");
    scanf("%lf", &num);
        
        do
        {
            pi += pow(-1,i)*4.0/somador;
            somador += 2;
            i++;  
        } 
        while (fabs(pi-M_PI) > num);
                        
        printf("%d\n", i);
return 0;
}