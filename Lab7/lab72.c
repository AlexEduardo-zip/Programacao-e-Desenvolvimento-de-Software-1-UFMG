#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fname[200];
    fgets(fname, 200, stdin);
    fname[strlen(fname)-1] = '\0';
    FILE *f = fopen(fname, "rb");


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