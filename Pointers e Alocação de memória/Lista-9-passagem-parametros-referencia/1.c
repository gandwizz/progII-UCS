// 1) Fazer uma função que troque o valor de duas variáveis inteiras informadas como parâmetro.
#include <stdio.h>

void trocavalor( int*num1, int*num2  ){
    int aux;
    aux = *num1;
    *num1 = *num2;
    *num2 = aux;
}

int main(){

    int num1 = 1;
    int num2 = 2;

    trocavalor(&num1, &num2);

    printf("num1: %d\nnum2: %d\n", num1,num2);
}