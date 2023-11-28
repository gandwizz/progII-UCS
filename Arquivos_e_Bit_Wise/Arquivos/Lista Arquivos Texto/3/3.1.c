#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char cpf[15];
    char nome[1000];
    char salario[1000];
    char setor[1000];
} FUNCIONARIO;

// Função de comparação para a qsort
int compararFuncionarios(const void *a, const void *b) {
    return strcmp(((FUNCIONARIO *)a)->nome, ((FUNCIONARIO *)b)->nome);
}

void ordenarFun(char nome_arquivo[18]){
    FILE *arquivoLeitura = fopen(nome_arquivo,"r");
    FILE *arquivoEscrita = fopen("funcionarios_ordenados.txt","wt");

    int nFuncionarios;
    fscanf(arquivoLeitura, "%d", &nFuncionarios);

    FUNCIONARIO *funcionarios = malloc(nFuncionarios * sizeof(FUNCIONARIO));

    // Leitura dos funcionários
    for (int i = 0; i < nFuncionarios; ++i) {
        fscanf(arquivoLeitura, "%s %999[^\n] %s %999[^\n]",
               funcionarios[i].cpf, funcionarios[i].nome,
               funcionarios[i].salario, funcionarios[i].setor);
    }

    // Ordenação dos funcionários pelo nome usando qsort
    qsort(funcionarios, nFuncionarios, sizeof(FUNCIONARIO), compararFuncionarios);

    // Impressão dos funcionários ordenados
    for (int i = 0; i < nFuncionarios; ++i) {
        fprintf(arquivoEscrita, "CPF: %s\nNome: %s\nSalário: %s\nSetor: %s\n\n",
                funcionarios[i].cpf, funcionarios[i].nome,
                funcionarios[i].salario, funcionarios[i].setor);
    }

    fclose(arquivoLeitura);
    fclose(arquivoEscrita);
    free(funcionarios);
}

int main(){
    ordenarFun("contabilidade.txt");
    return 0;
}
