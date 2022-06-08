#include <stdio.h>
#include <math.h>

int main()
{
    int ini;
    int fim;

    printf("Digite o intervalo: ");
    scanf("%d %d", &ini, &fim);

    for (int n = ini; n <= fim; n++)
    {
        int ehprimo;
        switch (n)
        {
        case 0:
            ehprimo = 0 ;
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
        for (int i = 2; ehprimo && i * i <= n ; i++)
        {
            if (n % i == 0)
            {
                ehprimo = 0;
            }
        }
        ehprimo? printf("%d\n", n) : 0;
    }
return 0;
}