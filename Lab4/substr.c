#include <stdio.h>
#include <string.h>

int main()
{
    char string1[100];
    printf("digite a primeira string: ");
    fgets(string1, 100, stdin);
    string1 [strlen(string1)-1] = '\0';
    char string2[100];
    printf("digite a segunda string: ");
    fgets(string2, 100, stdin);
    string2 [strlen(string2)-1] = '\0';

    int ehsubstring = 0;

    for (int i = 0; i < strlen(string1); i++)
    {
        if (string1[i] == string2[0])
        {
            int j;
            for (j = 1; j < strlen(string2); j++)
            {
                if (string1[i + j] != string2[j])
                {
                    break;
                }
            }
            if (j == strlen(string2))
            {
                ehsubstring = 1;
            }
        }
    }
    if (ehsubstring == 1)
    {
        printf("É substring");
    }
    if (ehsubstring == 0)
    {
        printf("Não é substring");
    }
}