#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct funcionario{
    char nome[100];
    float salario;
    int data[3];
    char departamento[100];
};
struct funcionario funcionarios[1000];
int quantFunc;
char linha[100];

void printaFunc(struct funcionario func){
    printf("%s\n",func.nome);
    printf("%.2f\n",func.salario);
    if(func.data[0] < 10){
        printf("0%d/",func.data[0]);
    }else{
        printf("%d/",func.data[0]);
    }
    if(func.data[1] < 10){
        printf("0%d/",func.data[1]);
    }else{
        printf("%d/",func.data[1]);
    }
    printf("%d\n",func.data[2]);
    printf("%s\n",func.departamento);
}

void coletaDados(char in[100]){
    FILE *arquivo;
    arquivo = fopen(in, "r");
    fscanf(arquivo,"%d",&quantFunc);
    for(int i = 0; i < quantFunc; i++){
        fseek(arquivo, 1, SEEK_CUR); //mudar o offset pra 2
        fscanf(arquivo,"%[^\n]%*c",funcionarios[i].nome);
        fscanf(arquivo,"%f",&funcionarios[i].salario);
        fscanf(arquivo,"%d/%d/%d",&funcionarios[i].data[0],&funcionarios[i].data[1],&funcionarios[i].data[2]);
        fscanf(arquivo,"%s",funcionarios[i].departamento);
    }
    fclose(arquivo);
}

void ordenaNome(){
    struct funcionario x; struct funcionario aux;
    int j;
    for(int i = 1; i < quantFunc; i++){
        x = funcionarios[i]; j = i-1;
        while(strcmp(x.nome, funcionarios[j].nome) < 0){
           aux = funcionarios[j];
           funcionarios[j] = x;
           funcionarios[j+1] = aux;
           j--; 
        }
    }
}

void exporta(char out[100]){
    FILE *arquivo;
    arquivo = fopen(out, "w");
    for(int i = 0; i < quantFunc; i++){
        fprintf(arquivo, "%s\n",funcionarios[i].nome);
        fprintf(arquivo, "%.2f\n",funcionarios[i].salario);
        if(funcionarios[i].data[0] < 10){fprintf(arquivo,"0%d/",funcionarios[i].data[0]);}
        else{fprintf(arquivo,"%d/",funcionarios[i].data[0]);}
        if(funcionarios[i].data[1] < 10){fprintf(arquivo,"0%d/",funcionarios[i].data[1]);}
        else{fprintf(arquivo,"%d/",funcionarios[i].data[1]);}
        fprintf(arquivo,"%d\n",funcionarios[i].data[2]);
        fprintf(arquivo, "%s\n",funcionarios[i].departamento);
    }
    fclose(arquivo);
}

void listarD(char dep[50]){
    for(int i = 0; i < quantFunc; i++){
        if(strcmp(funcionarios[i].departamento,dep) == 0){
            printaFunc(funcionarios[i]);
        }
    }
}

int antigoData(int d1[3], int d2[3]){
    if(d1[2] < d2[2]){return 1;}
    else if(d1[2] > d2[2]){return 0;}
    if(d1[1] < d2[1]){return 1;}
    else if(d1[1] > d2[1]){return 0;}
    if(d1[0] < d2[0]){return 1;}
    return 0;
}

void maisAntigo(){
    struct funcionario antigo;
    antigo = funcionarios[0];
    for(int i = 1; i < quantFunc; i++){
        if(antigoData(funcionarios[i].data, antigo.data)){
            antigo = funcionarios[i];
        }
    }
    printaFunc(antigo);
}

void maisAntigoD(char dep[100]){
    struct funcionario antigo;
    antigo.data[0] = 99; antigo.data[1] = 99; antigo.data[2] = 9999;
    for(int i = 0; i < quantFunc; i++){
        if(antigoData(funcionarios[i].data, antigo.data) && (strcmp(funcionarios[i].departamento,dep) == 0)){
            antigo = funcionarios[i];
        }
    }
    printaFunc(antigo);
}

void media(){
    double media = 0;
    for(int i = 0; i < quantFunc; i++){
        media += funcionarios[i].salario;
    }
    printf("%.2lf",media/quantFunc);
}

void mediaD(char dep[100]){
    double media = 0;
    int cont = 0;
    for(int i = 0; i < quantFunc; i++){
        if(strcmp(funcionarios[i].departamento, dep) == 0){
            media += funcionarios[i].salario; cont++;
        }
    }
    printf("%.2lf",media/cont);
}

void main(int argc, char *argv[]){
    coletaDados(argv[1]);
    ordenaNome();
    if (strcmp(argv[2],"1") == 0){exporta(argv[3]);}
    else if (strcmp(argv[2],"2") == 0){listarD(argv[3]);}
    else if (strcmp(argv[2],"3") == 0){maisAntigo();}
    else if (strcmp(argv[2],"4") == 0){maisAntigoD(argv[3]);}
    else if (strcmp(argv[2],"5") == 0){media();}
    else if (strcmp(argv[2],"6") == 0){mediaD(argv[3]);}
}
