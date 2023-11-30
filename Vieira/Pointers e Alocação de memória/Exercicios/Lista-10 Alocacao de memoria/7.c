// Faça uma função naonulos que recebe uma matriz de inteiros M[5][5] e aloca um vetor de naonulo de tamanho igual à quantidade de elementos diferentes de 0 na matriz, e coloca nele os elementos não nulos da matriz recebida, retornando, como valor de retorno da função, o endereço para o vetor alocado.

// A função deve retornar NULL se não há houverem elementos não nulos. Além disso, a função deverá retornar o número de elementos não nulos através de um argumento. O protótipo da função é dado por:

// NAONULOS* valores_nao_nulos(int M[5][5],  int *num_nao_nulos)

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct{
    int valor;
    int lin;
    int col;
} naonulos;


NAONULOS * valores_nao_nulos(int M[5][5],  int *num_nao_nulos){
    int i, j, k = 0;
    naonulos *vetor;
    vetor = (naonulos*) malloc(sizeof(naonulos));
    for(i = 0; i < 5; i++){
        for(j = 0; j < 5; j++){
            if(M[i][j] != 0){
                vetor = (naonulos*) realloc(vetor, (k+1)*sizeof(naonulos)); //realoca o vetor para o tamanho de k+1 mas não é muito eficiente
                vetor[k].valor = M[i][j];
                vetor[k].lin = i;
                vetor[k].col = j;
                k++;
            }
        }
    }
    *num_nao_nulos = k;
    return k > 0 ? vetor : NULL;
}
