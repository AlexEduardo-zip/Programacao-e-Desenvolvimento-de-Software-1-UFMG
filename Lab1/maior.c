#include <stdio.h>
#include <math.h>

int main (){

    int a,b,c,aux;
            printf("Digite os numeros inteiros: ");
            scanf("%d%d%d",&a,&b,&c);
            aux = a;
    if (b>aux)
        aux = b;
    if (c>aux){
            aux = c;
    }
        printf("%d",aux);
}