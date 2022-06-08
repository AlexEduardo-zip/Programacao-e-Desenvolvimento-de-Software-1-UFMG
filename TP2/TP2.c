#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Estrutura de data
typedef struct
{
    int dia;
    int mes;
    int ano;
} DATA;

//Estrutura de dados dos funcionarios
typedef struct
{
    char nome[50];
    float salario;
    DATA admissao;
    char departamento[50];
} cad;

//Essas são as funçoes do programa

//Função para mostrar os dados na tela
void printar(cad x)
{
    printf("%s\n", x.nome);
    printf("%.2f\n", x.salario);
    if (x.admissao.dia < 10)
        printf("0%d/", x.admissao.dia);
    else
        printf("%d/", x.admissao.dia);
    if (x.admissao.mes < 10)
        printf("0%d/", x.admissao.mes);
    else
        printf("%d/", x.admissao.mes);
    printf("%d\n", x.admissao.ano);
    printf("%s\n", x.departamento);
}

//Função que compara a data de admissão entre os funcionarios
int menorData(cad func1, cad func2)
{
    if (func1.admissao.ano < func2.admissao.ano)
        return 1;
    else if (func1.admissao.ano > func2.admissao.ano)
        return 0;
    if (func1.admissao.mes < func2.admissao.mes)
        return 1;
    else if (func1.admissao.mes > func2.admissao.mes)
        return 0;
    if (func1.admissao.dia < func2.admissao.dia)
        return 1;
    return 0;
}

//Inicio do programa
int main(int argc, char *argv[]) //Passagem de paramentros
{
    FILE *f; //Declaração do arquivo
    f = fopen(argv[1], "r"); //abertura do arquivo em modo de leitura
    if (f == NULL)
    {
        perror("Erro: ");
        return EXIT_FAILURE; //Verificação de erro ao abrir o arquivo
    }
    int nregistro;
    cad funcionarios[1000];
    fscanf(f, "%d", &nregistro); //Leitura do primeiro dado do arquivo que informa a quantidade de funcionarios
    for (int i = 0; i < nregistro; i++) //Varre todo o arquivo guardando os dados na estrutura 
    {
        fseek(f, 1, SEEK_CUR);
        fscanf(f, "%[^\n]%*c", funcionarios[i].nome);
        fscanf(f, "%f", &funcionarios[i].salario);
        fscanf(f, "%d/%d/%d", &funcionarios[i].admissao.dia, &funcionarios[i].admissao.mes, &funcionarios[i].admissao.ano);
        fscanf(f, "%s", funcionarios[i].departamento);
    }

    //Ordenação dos funcionarios em ordem alfabetica
    cad func1;
    cad func2;
    int aux;
    for (int i = 1; i < nregistro; i++) //Varre toda estrutura
    {
        func1 = funcionarios[i]; //Atribui um funcionario a estrutura auxiliar
        aux = i - 1; //Variavel auxiliar para pegar o funcionario anterior
        while (strcmp(func1.nome, funcionarios[aux].nome) < 0) //Laço com condição de string 1 ser menor que string 2
        {
            func2 = funcionarios[aux];
            funcionarios[aux] = func1;
            funcionarios[aux + 1] = func2;  //Feita a troca de posição dos dados dos funcionarios
            aux--;
        }
    }

    //Teste de entrada para função 1
    if (strcmp(argv[2], "1") == 0)
    {
        //Criação de arquivo para escrita e saida
        FILE *saida;
        saida = fopen(argv[3], "w");
        //Escrita dos dados dos funcionarios em ordem alfabetica no arquivo de saida
        for (int i = 0; i < nregistro; i++)
        {
            fprintf(saida, "%s\n", funcionarios[i].nome);
            fprintf(saida, "%.2f\n", funcionarios[i].salario);
            if (funcionarios[i].admissao.dia < 10)
                fprintf(saida, "0%d/", funcionarios[i].admissao.dia);
            else
                fprintf(saida, "%d/", funcionarios[i].admissao.dia);
            if (funcionarios[i].admissao.mes < 10)
                fprintf(saida, "0%d/", funcionarios[i].admissao.mes);
            else
                fprintf(saida, "%d/", funcionarios[i].admissao.mes);
            fprintf(saida, "%d\n", funcionarios[i].admissao.ano);
            fprintf(saida, "%s\n", funcionarios[i].departamento);
        }
    }

    //Teste para entrada na função 2
    if (strcmp(argv[2], "2") == 0)
    {
        //Varre os dados de todos funcionarios
        for (int i = 0; i < nregistro; i++)
        {
            if (strcmp(funcionarios[i].departamento, argv[3]) == 0) //Condição para execução somente dos funcionarios do departamento solicitado
                printar(funcionarios[i]); //Chamada da função que exibe na tela os dados do funcionario[i]
        }
    }

    // Teste para entrada na função 3
    if (strcmp(argv[2], "3") == 0)
    {
        //Criação de um funcionario aux sendo o funcionario mais recente possivel
        cad maisAntigo;
        maisAntigo.admissao.dia = 32;
        maisAntigo.admissao.mes = 13;
        maisAntigo.admissao.ano = 9999;
        //Varredura de todos os funcionarios
        for (int i = 0; i < nregistro; i++)
        {
            //Teste de todos funcionarios com o atual mais antigo e atribuição ao aux caso seja verdadeiro
            if (menorData(funcionarios[i], maisAntigo))
                maisAntigo = funcionarios[i];
        }
        //Saida do funcionario mais antigo que foi atrubuido ao funcionario aux
        printar(maisAntigo);
    }

    //Teste para entrada na função 4
    if (strcmp(argv[2], "4") == 0)
    {
        //Imprimir na tela os dados do funcionario mais antigo do departamento out.
        cad maisAntigo;
        maisAntigo.admissao.dia = 32;
        maisAntigo.admissao.mes = 13;
        maisAntigo.admissao.ano = 9999;
        //Varredura de todos os funcionarios
        for (int i = 0; i < nregistro; i++)
        {
            //Teste de todos funcionarios do departamento com o atual mais antigo e atribuição ao aux caso seja verdadeiro
            if (menorData(funcionarios[i], maisAntigo) && (strcmp(funcionarios[i].departamento, argv[3]) == 0))
                maisAntigo = funcionarios[i];
        }
        //Saida do funcionario mais antigo que foi atrubuido ao funcionario aux
        printar(maisAntigo);
    }

    //Teste para entrar na função 5
    if (strcmp(argv[2], "5") == 0)
    {
        //Criação da variavel que guarda o valor total da soma dos salarios e varredura de todos funcionarios
        double somaSalario = 0;
        for (int i = 0; i < nregistro; i++)
        {
            somaSalario += funcionarios[i].salario;
        }
        //saida da soma dos salarios divido pela quantidade de funcionarios
        printf("%.2lf", somaSalario / nregistro);
    }

    //Teste para entrar na função 6
    if (strcmp(argv[2], "6") == 0)
    {
        //Criação da variavel que guarda o valor total da soma dos salarios e varredura de todos funcionarios
        double somaSalario = 0;
        //Declaração do contador dos funcionarios do departamento
        int count;
        for (int i = 0; i < nregistro; i++) //Varre todos funcionarios
        {
            //Teste do departamento do funcionario
            if (strcmp(funcionarios[i].departamento, argv[3]) == 0)
            {
                somaSalario += funcionarios[i].salario; //Soma dos valores dos salarios
                count++; //Atriubuição do contador a cada funcionario do departamento
            }
        }
        //saida da soma dos salarios divido pela quantidade de funcionarios
        printf("%.2lf", somaSalario / count);
    }
    fclose(f); //Fechamento do arquivo
    return EXIT_SUCCESS;
    return 0;
}