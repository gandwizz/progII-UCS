#include <stdio.h>

// Função para mostrar a representação binária de um número
void mostrabin(unsigned int conjunto) {
    int i;
    for (i = 31; i >= 0; i--) {
        printf("%d", conjunto >> i & 1);
    }
    printf("\n");  // Nova linha após a impressão completa
}

// Função para inserir um bit em um número
void insere(unsigned int *conjunto, int valor) { 
    unsigned int mascaraValor = 1 << valor;
    *conjunto |= mascaraValor;
}
// Função para remover um bit em um número
void remove (unsigned int *conjunto, int valor){
    unsigned int mascara = 1<<valor;
    *conjunto &= (~mascara);
}

void insere(unsigned int *conjunto, int valor) { 
    unsigned int mascaraValor = 1 << valor;
    *conjunto |= mascaraValor;
}

int testa (unsigned int conjunto, int valor) {
	unsigned int res = conjunto>>valor&1;
	return res;
    /**Isola o bit. Desloca o conjunto para a direita por X valores, e verifica se o digito isolado é 1
     * 
     * 011000
     * Verificar bit 4
     * 011000 >> 4&1 == 011
     * 
     * ai Então testa-se 01[1] == 1, caso for verdadeiro retorna 1, se não retorna 0 
    */
}

unsigned int intersecao (unsigned int c1, unsigned int c2){
    unsigned int conjunto = c1 & c2;
}

unsigned int uniao (unsigned int c1, unsigned int c2){
    unsigned int conjunto = c1 | c2; 

    /**00001110
     * 00001001
     * 00001111
    */

}

unsigned int diferenca (unsigned int c1, unsigned int c2){
    unsigned int conjunto = c1 & (~c2); 

    /**00001110
     * 00001100
     * espera-se: 00000010
    */

}

void rota_esq(unsigned int *c) {
    *c=(*c<<1)|(*c>>7);

    /**
     * 11010100 c inicial
     * c1 = 10101000 (*c<<1)
     * c2 = 00000001 (*c>>7)
     * c3 = 10101001
     *
     * c1 = 01010000 (*c<<2)
     * c2 = 00000011 (*c>>6)
     * c3 = 01010011
     * 
    */  
}

void rota_dir(unsigned int *c) {
    *c=(*c>>1)|(*c<<7);

    /**
     * 11010100 c inicial
     * c1 = 01101010 (*c>>1)
     * c2 = 00000000 (*c<<7)
     * c3 = 01101010
     *
     * c1 = 00110101 (*c>>2)
     * c2 = 00000000 (*c<<6)
     * c3 = 00110101
     * 
    */  
}


int main() {
    unsigned int numero = 0;

    printf("Numero inicial: ");
    mostrabin(numero);

    // Inserindo o bit de valor 3 no número
    insere(&numero, 3);
    printf("Numero apos insercao do bit 3: ");
    mostrabin(numero);

    // Inserindo o bit de valor 5 no número
    insere(&numero, 5);
    printf("Numero apos insercao do bit 5: ");
    mostrabin(numero);

    return 0;
}
