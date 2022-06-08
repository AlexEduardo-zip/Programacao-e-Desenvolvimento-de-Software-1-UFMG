#include <stdio.h>

int main()
{
    int soma=0;
    int valor;
    printf("Digite o valor: ");
    scanf("%d", &valor);
    for (int i = 1; i <= valor; i++)
    {
        soma += i;
    }
    printf("%d", soma);
return 0;
}
