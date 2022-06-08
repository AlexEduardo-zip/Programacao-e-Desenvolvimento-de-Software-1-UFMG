#include <stdio.h>
#include <string.h>

int main()
{
    int jogos;
    //printf("digite a quantidade de jogos:\n");
    scanf("%d", &jogos);
    for (int i = 1; i <= jogos; i++)
    {
        int tabu;
        //printf("Digite qual será o tamanho do tabuleiro:\n");
        scanf("%d", &tabu);

        char campo[tabu][tabu];

        for (int i = 0; i < tabu; i++)
        {
            for (int j = 0; j < tabu; j++)
            {
                scanf(" %c", &campo[i][j]);
            }
        }
        int jogadas;
        //printf("digite a quantidade de jogadas:\n");
        scanf("%d", &jogadas);

        int linha;
        int coluna;

        //Leitura do tabuleiro
        //for (int i = 0; i < tabu; i++)
        //{
        //    for (int j = 0; j < tabu; j++)
        //    {
        //        printf(" %c ", campo[i][j]);
        //    }
        //    printf("\n");
        //}

        int resultado = 1;

        for (int i = 0; i < jogadas;)
        {
            scanf(" %d %d ", &linha, &coluna);

            if (campo[linha][coluna] == 'b')
                resultado = 0;
            else
            {
                    if (campo[linha][coluna] == 'x')
                        campo[linha][coluna] = 'v';

                    if ((campo[linha][coluna - 1] == 'x') && (coluna - 1 >= 0))
                        campo[linha][coluna - 1] = 'v';

                    if ((campo[linha][coluna + 1] == 'x') && (coluna + 1 < tabu))
                        campo[linha][coluna + 1] = 'v';

                    if ((campo[linha - 1][coluna] == 'x') && (linha - 1 >= 0))
                        campo[linha - 1][coluna] = 'v';

                    if ((campo[linha + 1][coluna] == 'x') && (linha + 1 < tabu))
                        campo[linha + 1][coluna] = 'v';
                
            }
            i++;
        }

        //Leitura do campo
        //for (int i = 0; i < tabu; i++)
        //{
        //    for (int j = 0; j < tabu; j++)
        //    {
        //        printf(" %c ", campo[i][j]);
        //    }
        //    printf("\n");
        //}

        if (resultado == 0)
            printf("PERDEU\n");
        else
        {
            for (int i = 0; i < tabu; i++)
            {
                for (int j = 0; j < tabu; j++)
                {
                    if (campo[i][j] == 'x')
                    {
                        resultado = 2;
                    }
                }
            }
            if (resultado == 1)
            {
                printf("GANHOU\n");
            }
            if (resultado == 2)
            {
                printf("FALTOU TERMINAR\n");
            }
        }
    }
    return 0;
}