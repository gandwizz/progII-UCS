// 3) Faça um programa completo em C que leia o nome, o salário e a quantidade de dependentes de cada um dos QTDFUNC funcionários de uma empresa.  Após escreva em ordem alfabética o nome dos funcionários que recebem menos que a média dos salários de todos os funcionários e possuem mais que dois dependentes. Utilizar obrigatoriamente uma struct para armazenar as informações de cada funcionário. Usar #define para QTDFUNC.

#include <stdio.h>
#include <string.h>

#define QTDFUNC 10

float mediaSalarios = 0;
typedef struct stfuncionario {
    char nome[31];
    float salario;
    int dependentes;
} Funcionario;

void ordenacaoAlfabetica(Funcionario str[QTDFUNC]){
    Funcionario aux;
    for (int i = 0; i < QTDFUNC; i++){
        for (int j = i+1; j < QTDFUNC; j++){  
            if((strcmp(str[i].nome, str[j].nome) > 0)){
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
    //     scanf("%d", funcionarios[i].dependentes);
    // }

    Funcionario funcionarios[QTDFUNC] = {
        {"Jack", 5800.0, 2},
        {"Alice", 5000.0, 0},
        {"Frank", 6200.0, 5},
        {"Bob", 6000.0, 4},
        {"David", 7500.0, 1},
        {"Charlie", 4500.0, 2},
        {"Grace", 4900.0, 3},
        {"Eva", 5200.0, 0}, 
        {"Helen", 6800.0, 0},
        {"Ivy", 5100.0, 0}
    };
    float total = 0;

    for (int i = 0; i < QTDFUNC; i++){
        total += funcionarios[i].salario;
    }


    mediaSalarios = total / QTDFUNC;
    ordenacaoAlfabetica(funcionarios);

    printf("\n");
    printf("Funcionários ordenados por nome/dependente:\n");
    for (int i = 0; i < QTDFUNC; i++) {

        if ((funcionarios[i].salario < mediaSalarios) && (funcionarios[i].dependentes > 2) )
        {
            printf("Nome: %s, Salário: %.2f, Depententes:%d\n", funcionarios[i].nome, funcionarios[i].salario, funcionarios[i].dependentes);
        }
        
    }


}
