#include <stdio.h>
#include <stdlib.h>

void soma(int *vet1, int *vet2, int *vet3, int cout)
{
    for (int i = 0; i < cout; i++)
    {
        vet3[i] = vet1[i] + vet2[i];
    }
}
void imprime(int *soma, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", soma[i]);
    }
}
void leitura(int *vetor, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%i", &vetor[i]);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int **v = (int **)malloc(3 * sizeof(int *));
    for (int i = 0; i < 3; i++)
    {
        v[i] = (int *)malloc(n * sizeof(int));
    }
    leitura(v[0], n);
    leitura(v[1], n);
    soma(v[0], v[1], v[2], n);
    imprime(v[2], n);
    free(v[0]);
    free(v[1]);
    free(v[2]);
    free(v);
    return EXIT_SUCCESS;
}