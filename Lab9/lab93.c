#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    double c_sep;
    double c_pet;
    double l_sep;
    double l_pet;
    char tipo[50];
} iris;

double dist(iris x, iris y)
{
    return (x.c_pet - y.c_pet) * (x.c_pet - y.c_pet) + (x.l_pet - y.l_pet) * (x.l_pet - y.l_pet) + (x.c_sep - y.c_sep) * (x.c_sep - y.c_sep) + (x.l_sep - y.l_sep) * (x.l_sep - y.l_sep);
}
void classificar(iris ni, iris ri[], int n)
{
    float min = dist(ni, ri[0]);
    int indice_min = 0;
    for (int i = 1; i < n; i++)
    {
        double distancia_atual = dist(ni, ri[i]);
        if (distancia_atual < min)
        {
            min = distancia_atual;
            indice_min = i;
        }
    }
    strcpy(ni.tipo, ri[indice_min].tipo);
    printf("%s\n", ni.tipo);
}
void ler_registro(iris ri[], int n)
{
    for (int  i = 0; i < n; i++)
    {
        scanf("%lf %lf %lf %lf %s", &ri[i].c_sep, &ri[i].l_sep, &ri[i].c_pet, &ri[i].l_pet, ri[i].tipo);
    }
    
}
int main()
{
    int n;
    scanf("%d", &n);
    iris treinamento[n];
    ler_registro(treinamento, n);
    iris consulta;
    scanf("%lf %lf %lf %lf", &consulta.c_sep, &consulta.l_sep, &consulta.c_pet, &consulta.l_pet);
    classificar(consulta, treinamento,n);
    
    return EXIT_SUCCESS;
}