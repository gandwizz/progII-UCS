// 4) Fazer um programa completo em C que leia o  número da conta, o nome do cliente, o código do gerente e o saldo das QTDCONTAS contas de uma agencia bancaria e escreva para cada gerente a soma dos respectivos saldos.

#include <stdio.h>
#include <string.h>

#define QTDFUNC 10

typedef struct {
    int numero_conta;
    char nome_cliente[50];
    int codigo_gerente;
    float saldo;
} ContaBancaria;

int main(void) {
    ContaBancaria contas[QTDFUNC] = {
        {101, "João", 1, 4500.0},
        {102, "Maria", 1, 6000.0},
        {103, "Pedro", 2, 7500.0},
        {104, "Ana", 2, 5100.0},
        {105, "Carlos", 3, 6800.0},
        // Adicione mais contas aqui, se necessário
    };

    float saldos_por_gerente[10] = {0}; // Suponhamos até 10 códigos de gerente

    for (int i = 0; i < QTDFUNC; i++) {
        int codigo_gerente = contas[i].codigo_gerente;
        saldos_por_gerente[codigo_gerente] += contas[i].saldo;
    }

    // Imprime a soma dos saldos para cada gerente
    for (int i = 1; i <= 10; i++) { // Suponhamos até 10 códigos de gerente
        if (saldos_por_gerente[i] > 0) {
            printf("Gerente %d: Soma dos saldos = %.2f\n", i, saldos_por_gerente[i]);
        }
    }

    return 0;
}

