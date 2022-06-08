#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    char marca[50];
    float preco;
} produto_t;
int main()
{
    produto_t produtos[8];
    char buffer[300];
    for (int i = 0; i < 8; i++)
    {
        fgets(buffer, 300, stdin);
        sscanf(buffer, "%s %s %f", produtos[i].nome, produtos[i].marca, &produtos[i].preco);
    }
    int nmarcas = 1;
    for (int i = 1; i < 8; i++)
    {
        int achou = 0;
        for (int k = i - 1; k >= 0; k--)
        {
            if (strcmp(produtos[i].marca, produtos[k].marca) == 0)
            {
                achou = 1;
                break;
            }
        }
        if (achou == 0)
            nmarcas++;
    }
    typedef struct
    {
        char marca[50];
        int numero;
        float preco;
    } marcas_t;

    marcas_t stats[nmarcas];
    strcpy(stats[0].marca, produtos[0].marca);
    stats[0].numero = 1;
    stats[0].preco = produtos[0].preco;
    int cursor = 1;

    for (int i = 1; i <= 8; i++)
    {
        int achou = 0;
        for (int k = 0; k < cursor; k++)
        {
            if (strcmp(produtos[i].marca, stats[k].marca) == 0)
            {
                stats[k].numero++;
                stats[k].preco += produtos[i].preco;
                achou = 1;
                break;
            }
        }
        if (achou == 0)
        {
            strcpy(stats[cursor].marca, produtos[i].marca);
            stats[cursor].numero = 1;
            stats[cursor].preco = produtos[i].preco;
            cursor++;
        }
    }
    for (int i = 0; i < nmarcas; i++)
    {
        printf("%s %d\n", stats[i].marca, stats[i].numero);
    }
    float total = produtos[0].preco;
    for (int i = 1; i < 8; i++)
    {
        total += produtos[i].preco;
    }
    printf("media total %.2f\n", total/8);
    for (int i = 0; i < nmarcas; i++)
    {
        float mediaMarca = stats[i].preco / stats[i].numero;
        printf("media %s %.2f \n", stats[i].marca, mediaMarca);
    }
}
