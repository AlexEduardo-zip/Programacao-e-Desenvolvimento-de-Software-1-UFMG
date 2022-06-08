#include <stdio.h>
#include <string.h>

int main(){

    char string1[100];
    char string2[100];
    char string3[200];

    printf("Digite a primeira string: \n");
    fgets(string1, 100, stdin);

    printf("Digite a segunda string: \n");
    fgets(string2, 100, stdin);

    string1 [strlen(string1)-1] = '\0';

    printf("%s", strcat(string1, string2));
};