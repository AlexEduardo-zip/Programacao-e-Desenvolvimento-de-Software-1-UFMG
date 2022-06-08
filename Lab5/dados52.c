#include <stdio.h>
#include <string.h>

struct adress
{
    char rua[50];
    unsigned int num;
    char estado[50];
};

typedef struct cadastro
{
    char nome[50];
    unsigned int idade;
    float salario;
    struct adress ender;
} cad;
cad pessoa[4];
int cursor = 0;
char comando[50] = "inicio";
char inserir[50] = "inserir";
char mostrar[50] = "mostrar";
char alterar[50] = "alterar";
int main()
{
    while (fgets(comando, 50, stdin) != NULL)
    {
        comando[strlen(comando) - 1] = '\0';
        //printf("comando: %s \n", comando);

        if (strcmp(comando, inserir) == 0)
        {
            char buffer[300];
            fgets(buffer, 300, stdin);
            if (cursor <= 4)
            {
                sscanf(buffer, "%s %u %f %s %u %s", pessoa[cursor].nome, &pessoa[cursor].idade, &pessoa[cursor].salario, pessoa[cursor].ender.rua, &pessoa[cursor].ender.num, pessoa[cursor].ender.estado);
                printf("Registro %s %u %.2f %s %u %s inserido \n", pessoa[cursor].nome, pessoa[cursor].idade, pessoa[cursor].salario, pessoa[cursor].ender.rua, pessoa[cursor].ender.num, pessoa[cursor].ender.estado);
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
                    printf("Registro %s %u %.2f %s %u %s \n", pessoa[i].nome, pessoa[i].idade, pessoa[i].salario, pessoa[i].ender.rua, pessoa[i].ender.num, pessoa[i].ender.estado);
                    break;
                }
            }
            if (achou == 0)
                printf("Registro ausente\n");
        }
        else if (strcmp(comando, alterar) == 0)
        {
            int achou = 0;
            cad altera;
            char buffer2[300];
            fgets(buffer2, 300, stdin);
            sscanf(buffer2, "%s %u %f %s %u %s", altera.nome, &altera.idade, &altera.salario, altera.ender.rua, &altera.ender.num, altera.ender.estado);

            for (int i = 0; i < cursor; i++)
            {
                if (strcmp(altera.nome, pessoa[i].nome) == 0)
                {
                    pessoa[i] = altera;
                    printf("Registro %s %d %.2f %s %u %s alterado\n", pessoa[i].nome, pessoa[i].idade, pessoa[i].salario, pessoa[i].ender.rua, pessoa[i].ender.num, pessoa[i].ender.estado);
                    achou = 1;
                    break;
                }
            }
            if (achou == 0)
                printf("Registro ausente para alteracao\n");
        }
    }
}