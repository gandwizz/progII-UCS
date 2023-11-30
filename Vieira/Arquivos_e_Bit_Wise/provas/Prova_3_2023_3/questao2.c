// (2.5 pontos)  Faça uma função que receba um inteiro sem sinal de 16 bits e inverta a posição de
// seus bits (troque o bit 0 com o 15, o 1 com o 14 e assim por diante) retornando, no próprio
// parâmetro recebido, o valor resultante das trocas.

#include <stdio.h>

void mostraNumeroBinario(unsigned int num) {
    for (int i = 15; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

unsigned int inverteBits(unsigned int num) {
    unsigned int resultado = 0;

    for (int i = 0; i < 16; i++) {
        unsigned int bit = (num >> i) & 1;  // Obtém o i-ésimo bit
        resultado |= (bit << (15 - i));     // Define o bit no resultado trocando-o
    }

    return resultado;
}

int main() {
    unsigned int numero = 0b00001111;  // Exemplo binário

    printf("Número original: ");
    mostraNumeroBinario(numero);

    unsigned int resultado = inverteBits(numero);

    printf("Número invertido: ");
    mostraNumeroBinario(resultado);

    return 0;
}
