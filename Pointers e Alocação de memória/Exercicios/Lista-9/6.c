
/*
6) Faça uma função que receba como parâmetro uma matriz M[15][15] e retorne: o menor número primo da matriz e a sua respectiva posição (linha e coluna). O protótipo da função é dado por:

Protótipo da função:

void menor_primo(int M[15][15], int *primo, int *lin, int *col)

A função deverá retornar: primo=-1, col=-1 e lin=-1 se não existir nenhum número primo na matriz. Faça também o programa principal que deverá ler a matriz e após escrever: o menor número primo da matriz e a sua respectiva posição. Esses valores deverão ser retornados pela função implementada
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ehPrimo(int *num) {
    if (*num < 2)
        return 0;

    for (int i = 2; i * i <= *num; i++) {
        if (*num % i == 0) {
            return 0;
        }
    }

    return 1;
}

void menor_primo(int M[15][15], int *primo, int *lin, int *col){

    *primo = -1;
    *lin = -1;
    *col = -1;

    for (int i = 0; i < 15; i++){
        for(int j = 0; j< 15; j++){
            if (ehPrimo(&M[i][j]) == 1){
                
                if( *primo == -1 || M[i][j] < *primo){
                    *primo = M[i][j];
                    *lin = i;
                    *col = j;
                }

            }
            
        
        }
    }
    

}