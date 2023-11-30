#include <stdio.h>

int main(void){

        int x; //separa 4bits na memória pra armazenar um int X
        x = 10; // pega os endereços e coloca o valor 10

        int *ponteiro; // < tipo > * < nome > 
        ponteiro = &x; // o ponteiro é igual ao endereço de memória da variável X
        printf("%i\n", *ponteiro); // printa o valor do endereço de memória de X
        printf("%i\n", ponteiro); // printa o endereço da memória de X

        //%i permite entrada de dados no formato hexadecimal ou octal;
        //%d só permite numero inteiro com sinal no formato decimal;

        printf("%i\n", x); // X representa o valor
        printf("%i\n", &x); // &X indica o endereço da memória, ou seja, & acessa o endereço. 
}

int main(void){

        int x = 10;
        int *ponteiro;
        
        ponteiro = &x; //o ponteiro recebe o endereço de memória de X

        int y = 20;
        *ponteiro = y; // o valor do ponteiro recebe y. Como o ponteiro recebeu o endereço de memória de X, vai alterar o valor de X

        printf("%i %i\n", x, y); // = 20 20

}




