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

    int matrizt[linhas][colunas];

    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            matrizt[i][j] = matriz[i][j] * -1;
        }
    }
    
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("%d ", matrizt[i][j]);
        }
    }

    return 0;
}
