// 7) Considerando uma struct chamada PONTO, possuindo apenas a posição x e y (reais) do ponto. Implemente um programa que lê  as posições de N pontos (o valor de N é definido via diretiva #define) e ao final exiba  os dois pontos com maior distância entre si. Deve ser criada uma função que receba o vetor de pontos e retorne os dois pontos com maior distância entre si. A distância entre 2 pontos, é calculada a partir da equação:

// Protótipo da função:

// void maior_distancia(PONTOS p[N], PONTOS *p1, PONTOS *p2);


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

typedef struct {
    float x;
    float y;
} PONTOS;

void maior_distancia(PONTOS p[N], PONTOS *p1, PONTOS *p2){

}

int main(){
    int p[N];
    int *pontos = (int *)malloc(N * sizeof(int));
    pontos = p;
    
    for (int i = 0; i < N; i++){
        scanf('%d', pontos[i]);
    }
    
    
}
