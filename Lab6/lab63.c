#include <stdio.h>
#include <string.h>

int primo(long int n)
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

long int somaPrimo(long int quantidade)
{
    long int soma=0;
    long int aux=0;
    for (int i = 0; aux < quantidade; i++)
    {
        if(primo(i)==1)
        {
            soma += i;
            aux++;
        }
    }
    return soma;
}

int main()
{
    while (1)
    {
        char entrada[100];
        fgets(entrada, 100, stdin);
        entrada[strlen(entrada) - 1] = '\0';
        if (!strcmp(entrada, "\0"))
            break;

        long int numero;
        sscanf(entrada, "%ld", &numero);

        printf("%ld\n", somaPrimo(numero));
    }
}