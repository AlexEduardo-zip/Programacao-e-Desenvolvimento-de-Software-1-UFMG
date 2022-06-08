#include <stdio.h>
#include <string.h>

typedef struct cadastro
{
    char nome[50];
    unsigned int idade;
    float salario;
} cad;
cad pessoa[3];
int cursor = 0;
char comando[50] = "inicio";
char inserir[50] = "inserir";
char mostrar[50] = "mostrar";
int main()
{
    while (fgets(comando, 50, stdin) != NULL)
    {
        comando[strlen(comando) - 1] = '\0';
        //printf("comando: %s \n", comando);

        if (strcmp(comando, inserir) == 0)
        {
            char buffer[200];
            fgets(buffer, 200, stdin);
            if (cursor <= 3)
            {
                sscanf(buffer, "%s %u %f", pessoa[cursor].nome, &pessoa[cursor].idade, &pessoa[cursor].salario);
                printf("Registro %s %d %.2f inserido \n", pessoa[cursor].nome, pessoa[cursor].idade, pessoa[cursor].salario);
                cursor++;
            }
            else
                printf("Espaco insuficiente\n");
        }
        else if (strcmp(comando, mostrar) == 0)
        {
            char nomeMostra[50];
            fgets(nomeMostra, 50, stdin);
            nomeMostra[strlen(nomeMostra) - 1] = '\0';
            //printf("pedido de amostra: %s", nomeMostra);
            int achou = 0;
            int i = 0;
            for (i = 0; i < cursor; i++)
            {
                if (strcmp(nomeMostra, pessoa[i].nome) == 0)
                {
                    achou = 1;
                    printf("Registro %s %u %.2f \n", pessoa[i].nome, pessoa[i].idade, pessoa[i].salario);
                    break;
                }
            }
            if (achou ==0 )
            printf("Registro ausente\n");
        }
    }
}