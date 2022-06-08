#include <stdio.h>
#include <string.h>

int main(){
    char string1[100];
    printf("digite a palavra: ");
    fgets(string1, 100, stdin);

    char carac[100];
    printf("digite a 1 letra: ");
    fgets(carac, 100, stdin);

    char carac2[100];
    printf("digite a letra para substituir: ");
    fgets(carac2, 100, stdin);
    
    for (int i = 0; i < strlen(string1) ; i++)
    {
        if (string1[i] == carac[0])
        {
            string1[i] = carac2[0];
            break;
        }
        
    }
    fputs(string1, stdout);
}