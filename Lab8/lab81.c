#include <stdio.h>
#include <stdlib.h>
void media (double vet[], int n, int *i)
{
    double media=0;
    for (int i = 0; i < n; i++)
    {
        media += vet[i];
    }
    media /= n;
    int menor=0;
    double diferenca = vet[0] - media;
    
    for (int i = 0; i < n; i++)
    {
        double ref = vet[i] - media;
        if((vet[i] - media)<0)
        ref = (vet[i] - media) * (-1);
        if(diferenca < 0)
        diferenca = diferenca * (-1);
        if (ref <= diferenca)
        {
            menor = i;
            diferenca = vet[i] - media;
            //printf("%lf\n", media);
        }
    }
    *i = menor;
}
int main()
{
    int n; int indice;
    scanf("%d", &n);
    double v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &v[i]);
        //printf("%lf", v[i]);
    }
    media(v, n, &indice);
    printf("%d", indice);
    return 0;
}