#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pessoa
{
    char nome[50];
    int idade;
    struct Pessoa *filhos;
    int numFilhos;
};

struct Pessoa *buscaPessoa(struct Pessoa *pessoaAsc, char nomeProcurado[], int nivel, int imprimeNivel)
{
    struct Pessoa *busca;
    if (strcmp(pessoaAsc->nome, nomeProcurado) == 0)
    {
        if (imprimeNivel)
        {
            printf("%d\n", nivel);
        }
        return pessoaAsc;
    }
    for (int i = 0; i < pessoaAsc->numFilhos; i++)
    {
        busca = buscaPessoa(&pessoaAsc->filhos[i], nomeProcurado, nivel + 1, imprimeNivel);
        if (busca == NULL) continue;
        else return busca;
    }
    return NULL;
}

int main()
{
    int nPessoas;
    scanf("%d ", &nPessoas);

    struct Pessoa primeiraPessoa;
    char pessoaAsc[50];
    
    char buffer[300];
    fgets(buffer, 300, stdin);
    sscanf(buffer, "%s %d %s", primeiraPessoa.nome, &primeiraPessoa.idade, pessoaAsc);
    primeiraPessoa.numFilhos = 0;

    struct Pessoa *cads;

    for (int i = 1; i < nPessoas; i++)
    {        
        char nome[50];
        int idade;
        char asc[50];
        
        fgets(buffer, 300, stdin);
        sscanf(buffer, "%s %d %s", nome, &idade, asc);

        cads = buscaPessoa(&primeiraPessoa, asc, 0, 0);
        cads->numFilhos++;
        if (cads->numFilhos == 1)
            cads->filhos = malloc(1 * sizeof(struct Pessoa));
        else
            cads->filhos = (struct Pessoa *)realloc(cads->filhos, (cads->numFilhos) * sizeof(struct Pessoa));
        cads->filhos[cads->numFilhos - 1].idade = idade;
        cads->filhos[cads->numFilhos - 1].numFilhos = 0;
        strcpy(cads->filhos[cads->numFilhos - 1].nome, nome);
    }

    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        char buffer[300];
        fgets(buffer, 300, stdin);
        char asc[50];
        char nomeProcurado[50];
        sscanf("%s %s", nomeProcurado, asc);
        buscaPessoa(buscaPessoa(&primeiraPessoa, asc, 0, 0), nomeProcurado, 0, 1);
    }
    free(primeiraPessoa.filhos);
}