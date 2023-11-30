// Faça uma função que receba um inteiro sem sinal de 16 bits e efetue nele as
// seguintes alterações: a) Zere o bit 5; b) Ligue o bit 8; c) Inverta o bit 9. Retorne o valor resultante
// das trocas no próprio parâmetro recebido.

#include <stdio.h>

void mostrabin(unsigned int conjunto){
	int i;
	for (i=31;i>=0;i--) {
		printf("%d", conjunto >> i&1);
	}
    printf("\n");
}


void operacoes(unsigned int * num) {
    unsigned int mascara = 1<<4;
    *num &= ~mascara;

    mascara = 1<<7;
    *num |= mascara;

    mascara =1<<8;
    *num ^= mascara;

}



int main(){
    unsigned int num = 256;

    operacoes(&num);

    mostrabin(num);
}