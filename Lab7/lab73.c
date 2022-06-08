#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char fname[200];
    fgets(fname, 200, stdin);
    fname[strlen(fname) - 1] = '\0';
    FILE *f = fopen(fname, "rb");
    if (f == NULL)
    {
        perror("Erro: ");
        return EXIT_FAILURE;
    }
    long int m1[5][5], m2[5][5];
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf(f, "%ld", &m1[i][j]);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            fscanf(f, "%ld", &m2[i][j]);
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%ld ", m1[i][j] + m2[i][j]);
        }
    }
    return EXIT_SUCCESS;
}
