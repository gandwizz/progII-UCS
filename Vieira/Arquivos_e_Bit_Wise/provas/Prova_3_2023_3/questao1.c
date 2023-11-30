// (2.5 pontos) Faça uma função que receba um inteiro sem sinal de 16 bits e efetue nele as
// seguintes alterações: a) Zere o bit 5; b) Ligue o bit 8; c) Inverta o bit 9. Retorne o valor resultante
// das trocas no próprio parâmetro recebido



#include <stdio.h>
#include <string.h>
#include <stdlib.h>


unsigned int funcao( unsigned int num){

    //zerar o bit 5
    num &= ~(1<<5);

    //ligar bit 8
    num |= 1 << 8;

    unsigned int mascara2 = num;
    num ^= 1 << 9;

    /**
     * 0000 000[0] 0000 0100 XOR 
     * 0000 000[1] 0000 0000
     * 
     * 0000 0001 0000 0100
     * 0000 0001 0000 0100
     * 0000 0000 0000 0100
    */

    return num;
}