
// Onde o primeiro número (5 no exemplo) corresponde ao número de funcionários e para cada funcionário tem-se: CPF, nome, salário e departamento. Gerar um novo arquivo texto com as mesmas informações mas com os funcionários ordenados de acordo com o nome (um funcionário por linha).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cpf[16];
    char nome[1000];
    char salario[1000];
    char setor[1000];
} FUNCIONARIO;

void ordenarFun(char nome_arquivo[18]){
    //Alocar uma string de structs do tipo FUNCIONÁRIO conforme o número que vem da primeira linha

    /**
     * 1° - Abrir arquivo
     * 2° - Criar novo arquivo também
     * 3° - Alocar string de structs do tipo FUNCIONÁRIO conforme a informação do número de funcionários existêntes
    */
    FILE *arquivoLeitura = fopen(nome_arquivo,"r"); //abertura do arquivo para leitura
    FILE *arquivoEscrita = fopen("funcionarios.txt","wt"); //abertura do arquivo para escrita
    
    int nFuncionarios;
    char linha[1000]; //tamanho máximo da linha
    fgets(linha,200,arquivoLeitura);
    sscanf(linha, "%d", &nFuncionarios);
    
    FUNCIONARIO *funcionarios = malloc(nFuncionarios * sizeof(FUNCIONARIO)); 

    
    for (int i = 0; i < nFuncionarios; ++i) {

        fgets(funcionarios[i].cpf, sizeof(funcionarios[i].cpf), arquivoLeitura);
        fgets(funcionarios[i].nome, sizeof(funcionarios[i].nome), arquivoLeitura);
        fgets(funcionarios[i].salario, sizeof(funcionarios[i].salario), arquivoLeitura);
        fgets(funcionarios[i].setor, sizeof(funcionarios[i].setor), arquivoLeitura);
    }

    for (int i = 0; i < nFuncionarios; i++){
        printf("CPF:%s",funcionarios[i].cpf);
        printf("NOME:%s",funcionarios[i].nome);
        printf("SALARIO:%s",funcionarios[i].salario);
        printf("SETOR:%s\n",funcionarios[i].setor);
    }
    
    
    //Bubble sort
    for (int i = 0; i < nFuncionarios-1; i++){
        for (int j = i+1; j < nFuncionarios; j++){
        
            if(strcmp(funcionarios[i].nome, funcionarios[j].nome ) > 0 ){
                FUNCIONARIO aux;
                aux = funcionarios[i];
                funcionarios[i] = funcionarios[j];
                funcionarios[j] = aux;
            }
        }
    } 

    // Impressão dos funcionários ordenados
    for (int i = 0; i < nFuncionarios; ++i) {
        fprintf(arquivoEscrita, "CPF: %s\nNome: %s\nSalário: %s\nSetor: %s\n\n",
                funcionarios[i].cpf, funcionarios[i].nome,
                funcionarios[i].salario, funcionarios[i].setor);
    }


    fclose(arquivoLeitura);
    fclose(arquivoEscrita);
};


int main(){

    ordenarFun("contabilidade.txt");

    return 0;
}