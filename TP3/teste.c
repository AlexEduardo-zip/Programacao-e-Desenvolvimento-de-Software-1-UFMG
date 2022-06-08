#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Pessoa {
    char nome[50];
    int idade, numFilhos;
    struct Pessoa *filhos;
};

struct Pessoa *buscaPessoa(struct Pessoa *pessoaAsc, char nomeProcurado[], int nivel, int imprimeNivel){
    struct Pessoa *buscada;
    if(strcmp(pessoaAsc->nome,nomeProcurado) == 0){
        if(imprimeNivel){printf("%i\n",nivel);}
        return pessoaAsc;
    }
    for(int i = 0; i < pessoaAsc->numFilhos; i++){
        buscada = buscaPessoa(&pessoaAsc->filhos[i], nomeProcurado, nivel+1, imprimeNivel);
        if(buscada == NULL){
            continue;
        } else {
            return buscada;
        }
    }
    return NULL;
}

void cadastraPessoa(struct Pessoa *pessoaAsc, char nome[], int idade, char asc[]){
    struct Pessoa *buscada;
    buscada = buscaPessoa(pessoaAsc, asc, 0, 0);
    buscada->numFilhos++;
    if(buscada->numFilhos == 1){
        buscada->filhos = malloc(1*sizeof(struct Pessoa));
    } else {
        buscada->filhos = (struct Pessoa *)realloc(buscada->filhos, (buscada->numFilhos)*sizeof(struct Pessoa));
    }
    buscada->filhos[buscada->numFilhos - 1].idade = idade;
    buscada->filhos[buscada->numFilhos - 1].numFilhos = 0;
    strcpy(buscada->filhos[buscada->numFilhos - 1].nome, nome);
}

void main(){
    int n, idade;
    char nome[50], asc[50];
    scanf("%i",&n);
    struct Pessoa pessoaMaster;
    scanf("%s %i %s", pessoaMaster.nome, &pessoaMaster.idade, asc);
    pessoaMaster.numFilhos = 0;
    for(int i = 1; i < n; i++){
        scanf("%s %i %s", nome, &idade, asc);
        cadastraPessoa(&pessoaMaster, nome, idade, asc);
    }
    scanf("%i",&n);
    for(int i = 0; i < n; i++){
        scanf("%s %s", nome, asc);
        buscaPessoa(buscaPessoa(&pessoaMaster, asc, 0, 0), nome, 0, 1);
    }
    free(pessoaMaster.filhos);
}