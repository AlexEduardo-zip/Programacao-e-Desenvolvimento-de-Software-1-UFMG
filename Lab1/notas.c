#include <stdio.h>
#include <math.h>

int main (){
    int cedulas,n100,n50,n25,n10,n5,n2,n1;
    
    int valorNotas;
    
    printf("Digite o valor a ser distribuido: ");
    scanf(" %d",&valorNotas);

    n100 = (valorNotas/100);
    valorNotas = valorNotas % 100;
    
    n50 = valorNotas/50;
    valorNotas = valorNotas % 50;
    
    n25 = valorNotas/25;
    valorNotas = valorNotas % 25;

    n10 = valorNotas/10;
    valorNotas = valorNotas % 10;

    n5 = valorNotas/5;
    valorNotas = valorNotas % 5;

    n2 = valorNotas/2;
    valorNotas = valorNotas % 2;
    
    n1 = valorNotas/1;

    printf("O minimo de notas a ser usadas é: \n");
    printf("100:%d\n50:%d\n25:%d\n10:%d\n5:%d\n2:%d\n1:%d\n",n100,n50,n25,n10,n5,n2,n1);
return 0;
}