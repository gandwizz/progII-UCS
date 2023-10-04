// 2)Fazer uma função que encontre e retorne como parmetros o maior e o menor número que estão em um vetor com números (float).
// Protótipo: void maiormenor(float *vet, int tamvet, float *maior, float *menor)

#include <stdio.h>
#include <stdlib.h>

void maiormenor(float *vet, int tamvet, float *maior, float *menor){
    *maior = vet[0];
    *menor = vet[0];

    for(int i = 0; i < tamvet; i++){

        if(vet[i] > *maior){
            *maior = vet[i];
        }

        if(vet[i] < *menor){
            *menor = vet[i];
        }

    } 

}