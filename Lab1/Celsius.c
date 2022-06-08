#include <stdio.h>
#include <math.h>

int main (){
    float c,f;
    printf("Digite a temperatura em Celsius que deseja converter: ");
    scanf("%f",&c);
    printf("%.0f ", 1.8 * c + 32);
    return 0;
}