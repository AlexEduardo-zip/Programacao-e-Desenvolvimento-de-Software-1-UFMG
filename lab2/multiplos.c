#include <stdio.h>

int main(){
    
    int num;
    int d2=0;
    int d3=0;
    int d5=0;
    int dx=0;
    int i = 0;
    
    printf("insira o valor: ");
    scanf(" %d", &num);

    while (i < num)
    {
        i++;
        if ((i%2) == 0){
            d2 = d2+1;
        } if ((i%3) == 0){
            d3++;
          } if ((i%5) == 0){
            d5++;
            } if ((i%2) == 0 && (i%3 == 0) && (i%5) == 0){
                dx++;
            }
    }
        printf("Múltiplos de 2: %d\n",d2);
        printf("Múltiplos de 3: %d\n",d3);
        printf("Múltiplos de 5: %d\n",d5);
        printf("Múltiplos de todos: %d",dx);

return 0;
}