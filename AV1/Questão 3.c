/**
 3) Faça um programa que leia uma string e calcule a operação, escrevendo o resultado. As operações possíveis são "+", "-" e "/". Para facilitar, considere que:
 a)não existem espaços em branco na string
 b) na string existe somente uma operação
 c) sempre existem dois números inteiros na string. 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char verificaOperacao(char *str) {
    if (strchr(str, '+') != NULL) {
        return '+';
    } else if (strchr(str, '-') != NULL) {
        return '-';
    } else if (strchr(str, '*') != NULL) {
        return '*';
    } else if (strchr(str, '/') != NULL) {
        return '/';
    } else {
        return '0';
    }
}

int main(void) {
    char string[20];
    printf("Digite a operação (ex: 10+16): ");
    fgets(string, sizeof(string), stdin);

    char operacao = verificaOperacao(string);

    if (operacao != '0') {
        char *p = strtok(string, "+-*/");
        float resultado = atof(p);

        while (p != NULL) {
            p = strtok(NULL, "+-*/");
            if (p != NULL) {
                int numero = atoi(p);
                if (operacao == '+') {
                    resultado += numero;
                } else if (operacao == '-') {
                    resultado -= numero;
                } else if (operacao == '*') {
                    resultado *= numero;
                } else if (operacao == '/') {
                    if (numero == 0) {
                        printf("Divisão por zero não é permitida.\n");
                        return 1;
                    }
                    resultado /= numero;
                }
            }
        }
        printf("Resultado: %.2f\n", resultado);
    } else {
        printf("Operação inválida\n");
    }

    return 0;
}