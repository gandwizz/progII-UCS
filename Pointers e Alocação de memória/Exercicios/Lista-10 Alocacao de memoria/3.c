// 3) Faça uma função que receba por parâmetro um valor inteiro n e retorne um vetor de n inteiros alocado dinamicamente com os n primeiros termos da série de Fibonacci. Lembre-se que os 2 primeiros elementos da série de Fibonacci são 0 e 1 e cada próximo termo é a soma dos 2 anteriores a ele. Por exemplo, os 11 primeiros termos da série de Fibonacci são: 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55.

//protótipo : int * fibonacci( int n )
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int * fibonacci( int n ){
    int *vetor = (int*)malloc(n *sizeof(int));

    vetor[0] = 0; // primeiro termo
    vetor[1] = 1; // segundo termo

    for(int i = 2; i < n; i++){
        vetor[i] = vetor[i-1] + vetor[i-2];
    }

    return vetor;
}

int main(void){
    int *vetor = fibonacci(11);

    for(int i = 0; i < 11; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}
