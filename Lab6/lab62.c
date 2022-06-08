#include <stdio.h>
#include <string.h>

int numero(long int n)
{
    long int ehprimo;
    switch (n)
        {
        case 0:
            ehprimo = 0;
            break;
        case 1:
            ehprimo = 0;
            break;

        case 2:
            ehprimo = 1;
            break;

        default:
            ehprimo = 1;
            break;
        }
        for (long int i = 2; ehprimo && i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ehprimo = 0;
            }
        }
        return ehprimo;
}

int main()
{
     while (1)
    {
        char entrada[100];
        fgets(entrada, 100, stdin);
        entrada[strlen(entrada)-1]='\0';
        if(!strcmp(entrada, "\0"))
        break;

        long int numerodig;
        sscanf(entrada, "%ld", &numerodig);
        if (numerodig<2)
        printf("-1\n"); 
        else
        printf("%d\n", numero(numerodig));
    }
}