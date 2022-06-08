#include <stdio.h>

int main()
{
    int linhas;
    int colunas;
    scanf("%d %d", &linhas, &colunas);
    int matriz[linhas][colunas];

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            scanf(" %d ", &matriz[i][j]);
        }
    }
    int maior = matriz[0][0];

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (maior < matriz[i][j])
            {
                maior = matriz[i][j];
            }
        }
    }
    printf("\n%d", maior);
return 0;
}