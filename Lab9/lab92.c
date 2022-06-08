#include <stdio.h>
#include <stdlib.h>

void imprime(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%i ", vetor[i]);
    }
    printf("\n");
}

void multiplica(int vetor[], int n, double v)
{
    for (int i = 0; i < n; i++)
    {
        vetor[i] *= v;
    }
}

void ler_vetor(int vetor[], int n)
{
    for (int i = 0; i < n; i++)
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
    double c;
    scanf("%lf", &c);
    imprime(v, n);
    multiplica(v, n, c);
    imprime(v, n);
    multiplica(v, n, 1.0 / c);
    imprime(v, n);

    return EXIT_SUCCESS;
}