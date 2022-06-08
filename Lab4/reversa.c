#include <stdio.h>
#include <string.h>

int main(){
    char string1[100];
    fgets(string1, 100, stdin);

    for (int i = strlen(string1); i >= 0; i--)
    {
        printf("%c", string1[i]);
    }
    
}