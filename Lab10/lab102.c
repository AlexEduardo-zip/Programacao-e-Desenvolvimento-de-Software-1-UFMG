#include <stdio.h>
#include <stdlib.h>

int **alloca_matriz(int l, int c)
{
    int **matriz = (int **)malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++)
    {
        matriz[i] = (int *)malloc(c * sizeof(int));
    }
    return matriz;
}
void libera_matriz(int **m, int l)
{
    for (int i = 0; i < l; i++)
    {
        free(m[i]);
    }
    free(m);
}
void preenche_matriz(int **m, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
}
void imprime_matriz(int **m, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
        {
            printf("%3d ", m[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int n_linhas, n_colunas;
    scanf("%d %d", &n_linhas, &n_colunas);
    int **matriz = alloca_matriz(n_linhas, n_colunas);
    preenche_matriz(matriz, n_linhas, n_colunas);
    imprime_matriz(matriz, n_linhas, n_colunas);
    libera_matriz(matriz, n_linhas);
    return EXIT_SUCCESS;
}