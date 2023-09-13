/**
Considere um programa que armazena os dados referentes aos funcionáriso de uma empresa como um vetor de dados do tipo 
FUNCIONARIO, definido conforme o tipo estruturado a seguir

""
struct funcionario {
    int codigo;
    int nome[50];
    DATA nascimento;
    float valor_hora;
};
typedef struct funcionario FUNCIONARIO; 
""

O campo nascimento, que representa o dia, mês e ano e nascimento do funcionário é um campo do tipo DATA

struct data {
    int dia;
    int mes;
    int ano;

};

typedef struct data DATA; 


Escreva uma função em C que recebe como parâmetros um vetor de dados do tipo FUNCIONARIO e retorne
(em uma estrutura do tipo FUNCIONARIO) as informações do funcionário mais velho. O protótipo da
função é dado por: FUNCIONARIO mais_velho (FUNCIONARIO *vetor, int numeroFuncionarios)
*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct {
    int codigo;
    char nome[50];
    DATA nascimento;
    float valor_hora;
} FUNCIONARIO;

FUNCIONARIO mais_velho(FUNCIONARIO *funcionarios, int numeroFuncionarios) {
    FUNCIONARIO funcionario_mais_velho = funcionarios[0];

    for (int i = 1; i < numeroFuncionarios; i++) {
        if (funcionarios[i].nascimento.ano < funcionario_mais_velho.nascimento.ano ||
            (funcionarios[i].nascimento.ano == funcionario_mais_velho.nascimento.ano && funcionarios[i].nascimento.mes < funcionario_mais_velho.nascimento.mes) ||
            (funcionarios[i].nascimento.ano == funcionario_mais_velho.nascimento.ano && funcionarios[i].nascimento.mes == funcionario_mais_velho.nascimento.mes && funcionarios[i].nascimento.dia < funcionario_mais_velho.nascimento.dia)) {
            funcionario_mais_velho = funcionarios[i];
        }
    }

    return funcionario_mais_velho;
}

int main() {
    int numero_funcionarios = 0;
    scanf("%d", &numero_funcionarios);

    FUNCIONARIO funcionarios[numero_funcionarios];

    for (int i = 0; i < numero_funcionarios; i++) {
        scanf("%d", &funcionarios[i].codigo);
        scanf("%s", funcionarios[i].nome);
        scanf("%d/%d/%d", &funcionarios[i].nascimento.dia, &funcionarios[i].nascimento.mes, &funcionarios[i].nascimento.ano);
        scanf("%f", &funcionarios[i].valor_hora);
    }

    FUNCIONARIO funcionario_mais_velho = mais_velho(funcionarios, numero_funcionarios);

    printf("Funcionário mais velho:\n");
    printf("Código: %d\n", funcionario_mais_velho.codigo);
    printf("Nome: %s\n", funcionario_mais_velho.nome);
    printf("Data de Nascimento: %d/%d/%d\n", funcionario_mais_velho.nascimento.dia, funcionario_mais_velho.nascimento.mes, funcionario_mais_velho.nascimento.ano);
    printf("Valor por Hora: %.2f\n", funcionario_mais_velho.valor_hora);

    return 0;
}


/** USANDO DADOS PARA TESTE*/

#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} DATA;

typedef struct {
    int codigo;
    char nome[50];
    DATA nascimento;
    float valor_hora;
} FUNCIONARIO;

FUNCIONARIO mais_velho(FUNCIONARIO *funcionarios, int numeroFuncionarios) {
    FUNCIONARIO funcionario_mais_velho = funcionarios[0];

    for (int i = 1; i < numeroFuncionarios; i++) {
        if (funcionarios[i].nascimento.ano < funcionario_mais_velho.nascimento.ano ||
            (funcionarios[i].nascimento.ano == funcionario_mais_velho.nascimento.ano && funcionarios[i].nascimento.mes < funcionario_mais_velho.nascimento.mes) ||
            (funcionarios[i].nascimento.ano == funcionario_mais_velho.nascimento.ano && funcionarios[i].nascimento.mes == funcionario_mais_velho.nascimento.mes && funcionarios[i].nascimento.dia < funcionario_mais_velho.nascimento.dia)) {
            funcionario_mais_velho = funcionarios[i];
        }
    }

    return funcionario_mais_velho;
}

int main() {
    int numero_funcionarios = 3; // Defina o número de funcionários aqui.
    FUNCIONARIO funcionarios[3]; // Defina o tamanho do array de funcionários.

    // Dados de exemplo incorporados
    funcionarios[0].codigo = 101;
    strcpy(funcionarios[0].nome, "João Silva");
    funcionarios[0].nascimento.dia = 15;
    funcionarios[0].nascimento.mes = 3;
    funcionarios[0].nascimento.ano = 1985;
    funcionarios[0].valor_hora = 25.50;

    funcionarios[1].codigo = 102;
    strcpy(funcionarios[1].nome, "Maria Santos");
    funcionarios[1].nascimento.dia = 22;
    funcionarios[1].nascimento.mes = 6;
    funcionarios[1].nascimento.ano = 1990;
    funcionarios[1].valor_hora = 22.75;

    funcionarios[2].codigo = 103;
    strcpy(funcionarios[2].nome, "Pedro Almeida");
    funcionarios[2].nascimento.dia = 5;
    funcionarios[2].nascimento.mes = 11;
    funcionarios[2].nascimento.ano = 1980;
    funcionarios[2].valor_hora = 30.00;

    FUNCIONARIO funcionario_mais_velho = mais_velho(funcionarios, numero_funcionarios);

    printf("Funcionário mais velho:\n");
    printf("Código: %d\n", funcionario_mais_velho.codigo);
    printf("Nome: %s\n", funcionario_mais_velho.nome);
    printf("Data de Nascimento: %02d/%02d/%04d\n", funcionario_mais_velho.nascimento.dia, funcionario_mais_velho.nascimento.mes, funcionario_mais_velho.nascimento.ano);
    printf("Valor por Hora: %.2f\n", funcionario_mais_velho.valor_hora);

    return 0;
}

