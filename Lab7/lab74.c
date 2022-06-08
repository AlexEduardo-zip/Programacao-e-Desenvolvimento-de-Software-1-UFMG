#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nome[50];
    int idade;
    char numeroTelefone[20];
} agenda_t;

void inserir(agenda_t registro, agenda_t *a, int *n_registro)
{
    registro = *a;
    n_registro++;
}

void alterar(agenda_t registro, agenda_t *a)
{
}

void excluir(char nome[50], agenda_t a[100], int *nregistro)
{
}

void exibir(char nome[50], agenda_t a[100])
{
}

int main()
{
    char fname[200];
    fgets(fname, 200, stdin);
    fname[strlen(fname) - 1] = '\0';
    FILE *f = fopen(fname, "rb");
    if (f == NULL)
    {
        perror("Erro: ");
        return EXIT_FAILURE;
    }
    agenda_t agenda[100];
    int nregistro;
    nregistro = fread(agenda, sizeof(agenda_t), 100, f);
    

    printf("%d", nregistro);
    int cursor = 0;



    char buffer[300];
    char comando[50] = "inicio";
    char inserir[50] = "Inserir";
    char exibir[50] = "Exibir";
    char alterar[50] = "Alterar";
    char excluir[50] = "Excluir";
    char nomeVazio[5] = "null";

    while (fgets(comando, 15, stdin) != NULL)
    {
        comando[strlen(comando) - 1] = '\0';
        //printf("%s\n", comando);

        if (strcmp(comando, inserir))
        {
            if (nregistro < 100)

                    sscanf(buffer, "%s %d %ls", agenda[nregistro].nome, &agenda[nregistro].idade, agenda[nregistro].numeroTelefone);

                    printf("Registro %s %d %s", agenda[nregistro].nome, agenda[nregistro].idade, agenda[nregistro].numeroTelefone);
                    printf("inserido\n");
                    nregistro++;
        } else printf("Espaco insuficiente\n");

        if (strcmp(comando, alterar))
        {
            printf("alterado\n");
        }

        if (strcmp(comando, excluir))
        {
            printf("Excluido\n");
        }

        if (strcmp(comando, exibir))
        {
            char nomeMostra[50];
            fgets(nomeMostra, 50, stdin);
            nomeMostra[strlen(nomeMostra) - 1] = '\0';
            //printf("pedido de amostra: %s", nomeMostra);
            int achou = 0;
            int i = 0;
            for (i = 0; i < cursor; i++)
            {
                if (strcmp(nomeMostra, agenda[i].nome) == 0)
                {
                    achou = 1;
                    printf("Registro %s %d %s \n", agenda[i].nome, agenda[i].idade, agenda[i].numeroTelefone);
                    break;
                }
            }
            if (achou == 0)
                printf("Registro ausente\n");
            printf("Exibido\n");
        }
    }

    fclose(f);
    return EXIT_SUCCESS;
}