#include <stdio.h>

int soma(int vetor[], int tamanho_vetor)
{
    if (tamanho_vetor == 0)
        return 0;
    else
        return vetor[0] + soma(&vetor[1], tamanho_vetor - 1);
}
void ler_vetor(int vetor[], int count)
{
    for (int i = 0; i < count; i++)
    {
        scanf("%d", &vetor[i]);   
    }
    
}
int main()
{
    int n;
    scanf("%d", &n);
    int v[n];
    ler_vetor(v, n);
    printf("soma :%d\n", soma(v, n));
    return 0;
}
