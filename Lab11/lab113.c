#include <stdio.h>
#include <string.h>
int conta_caractere(char str[], char c)
{
    if (str[0] == '\0')
        return 0;
    else
    {
        if (str[0] == c)
            return 1 + conta_caractere(&str[1], c);
        else
            return 0 + conta_caractere(&str[1], c);
    }
}

int main()
{
    char palavra[50];
    fgets(palavra, 50, stdin);
    palavra[strlen(palavra) - 1] = '\0';
    char letra = getchar();
    printf("%d\n", conta_caractere(palavra, letra));
    return 0;
}
