// 2) Faça um programa que leia nomes e salários de 10 funcionários e escreva essas informações em ordem alfabética (nome) e depois em ordem decrescente de salário (maior para o menor). Armazene os dados lidos em structs como a seguir:

#include <stdio.h>
#include <string.h>

typedef struct stfuncionario {
    char nome[31];
    float salario;
} Funcionario;

void ordenacaoAlfabetica(Funcionario str[10]){
    Funcionario aux;
    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){  
            if(strcmp(str[i].nome, str[j].nome) > 0 ){
                aux = str[i];
                str[i] = str[j];
                str[j] = aux;
            }
        }
    }
    
}


void ordenacaoSalario(Funcionario str[10]){

    Funcionario aux;
    for (int i = 0; i < 10; i++){
        for (int j = i+1; j < 10; j++){
            if(str[i].salario < str[j].salario ){
                
                aux = str[i];
                str[i] = str[j];
                str[j] = aux;

            } else if(str[i].salario  == str[j].salario  && strcmp(str[i].nome, str[j].nome) > 0 ){
                aux = str[i];
                str[i] = str[j];
                str[j] = aux;
            }
        }
    }
    
}

int main(void){

    // Funcionario funcionarios[10];

    // for (int i = 0; i < 10; i++)
    // {
    //     scanf("%30s", funcionarios[i].nome);
    //     scanf("%f", funcionarios[i].salario);
    // }

    Funcionario funcionarios[10] = {
        {"Jack", 5800.0},
        {"Alice", 5000.0},
        {"Frank", 6200.0},
        {"Bob", 6000.0},
        {"David", 7500.0},
        {"Charlie", 4500.0},
        {"Grace", 4900.0},
        {"Eva", 5200.0},
        {"Helen", 6800.0},
        {"Ivy", 5100.0}
    };

    ordenacaoAlfabetica(funcionarios);

    printf("Funcionários ordenados por nome:\n");
    for (int i = 0; i < 10; i++) {
        printf("Nome: %s, Salário: %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }

    ordenacaoSalario(funcionarios);

    printf("\n");
    printf("Funcionários ordenados por salario:\n");
    for (int i = 0; i < 10; i++) {
        printf("Nome: %s, Salário: %.2f\n", funcionarios[i].nome, funcionarios[i].salario);
    }


}
