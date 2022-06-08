#include <stdio.h>
#include <stdlib.h>
typedef enum
{
    jan = 1,
    fev,
    mar,
    abr,
    maio,
    jun,
    jul,
    ago,
    set,
    out,
    nov,
    dez
} mes_t;

typedef struct
{
    int dia;
    mes_t mes;
    int ano;
} Data;

typedef struct
{
    char nome[100];
    char local[100];
    Data data;
} Evento;

void cadastrar_eventos(Evento agenda[], int n)
{
    char buffer[sizeof(Evento)];
    for (int i = 0; i < n; i++)
    {
        fgets(buffer, sizeof(Evento), stdin);
        sscanf(buffer, " %s %s %d %u %d ", agenda[i].nome, agenda[i].local, &agenda[i].data.dia, &agenda[i].data.mes, &agenda[i].data.ano);
    }
}

void imprimir_eventos(Evento agenda[], Data d, int n)
{
    int achou = 0;
    for (int i = 0; i < n; i++)
    {
        if ((d.dia == agenda[i].data.dia) && (d.mes == agenda[i].data.mes) && (d.ano == agenda[i].data.ano))
        {
            printf("%s %s\n", agenda[i].nome, agenda[i].local);
            achou = 1;
        }
    }
    if (!achou)
    {
        printf("Nenhum evento encontrado!\n");
    }
}

int main()
{
    int n;
    scanf(" %d ", &n);
    Evento agenda[n];
    cadastrar_eventos(agenda, n);
    Data dataconsulta;
    scanf("%d %u %d", &dataconsulta.dia, &dataconsulta.mes, &dataconsulta.ano);
    imprimir_eventos(agenda, dataconsulta, n);

    return 0;
}