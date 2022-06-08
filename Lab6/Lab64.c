#include <stdio.h>
#include <string.h>

int bisexto(int ano)
{
    return (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0));
}

int main()
{
    while (1)
    {
        char entrada[100];
        fgets(entrada, 100, stdin);
        entrada[strlen(entrada)-1]='\0';
        if(!strcmp(entrada, "\0"))
        break;
        
        int anodig;
        sscanf(entrada, "%d", &anodig);


        printf("%d\n", bisexto(anodig));
    }

    return 0;
}