#include <stdio.h>
#include <stdlib.h>

int main(int arg, char **argv)
{
    FILE *f = fopen(argv[1], "r");
    if (f == NULL)
    {
        printf("Erro na abertura do arquivo: \n");
    }

    char c;
    int contador=0;
    while ((c = fgetc(f))!= EOF)
    {
        if (c == 'a')
        contador++;
    }
    
    fclose(f);
    printf("%d\n", contador);
    return EXIT_SUCCESS;
    return 0;
}