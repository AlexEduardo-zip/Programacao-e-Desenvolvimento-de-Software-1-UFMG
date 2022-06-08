#include <stdio.h>
#include <string.h>

void apaga_caractere(char s1[], char s2[], char c)
{
    if (s1[0] != '\0')
    {
        if (s1[0] == c)
            apaga_caractere(&s1[1], s2, c);
        else
        {
            char t[2] = {s1[0], '\0'};
            strcat(s2, t);
            apaga_caractere(&s1[1], s2, c);
        }
    }
}
int main()
{
    char palavra[50];
    fgets(palavra, 50, stdin);
    palavra[strlen(palavra) - 1] = '\0';
    char saux[50];
    char letra = getchar();
    apaga_caractere(palavra, saux, letra);
    printf("%s\n", saux);
    return 0;
}