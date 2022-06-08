#include <stdio.h>
#include <string.h>

int bisexto(int ano)
{
    return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

typedef struct
{
    int dia;
    int mes;
    int ano;
}data_t;

int data2dias(data_t d)
{
    data_t ref = {1,1,1};
    float total = 0;
    total += (d.ano - ref.ano - 1) * 365.25;

    int meses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    for (int mes = d.mes; mes <= 12, mes++)
    {
        total -= meses[mes-1];
    }
    total += d.dia - ref.dia +1;

    if(bissexto(d.ano) && d.mes <=2)
    total--;

    return(int) total;
}

int diferecaDias(data_t dBase, data_t dDigitada)
{
    return data2dias(dBase) - data2dias(dDigitada);
}

int main()
{
    data_t datadigitada;
    data_t database;
    database.dia = 17;
    database.mes = 09;
    database.ano = 2020;

    while (1)
    {
        char entrada[100];
        fgets(entrada, 100, stdin);
        entrada[strlen(entrada) - 1] = '\0';
        if (!strcmp(entrada, "\0"))
            break;

        sscanf(entrada, "%d %d %d", &datadigitada.dia, &datadigitada.mes, &datadigitada.ano);

        printf("%d", diferecaDias(database, datadigitada));
    }