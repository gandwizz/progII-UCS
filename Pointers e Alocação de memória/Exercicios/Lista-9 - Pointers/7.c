// 7) Considerando uma struct chamada PONTO, possuindo apenas a posição x e y (reais) do ponto. Implemente um programa que lê  as posições de N pontos (o valor de N é definido via diretiva #define) e ao final exiba  os dois pontos com maior distância entre si. Deve ser criada uma função que receba o vetor de pontos e retorne os dois pontos com maior distância entre si. A distância entre 2 pontos, é calculada a partir da equação:

// Protótipo da função:

// void maior_distancia(PONTOS p[N], PONTOS *p1, PONTOS *p2);


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define N 5

typedef struct {
    float x;
    float y;
} PONTOS;


float distancia(PONTOS p1, PONTOS p2){
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void maior_distancia(PONTOS p[N], PONTOS *p1, PONTOS *p2){
    float maxDistancia = 0;

    for(int i = 0; i < N; i++){
        for(int j = i+1 ; j < N; j++){
            float dist = distancia(p[i], p[j]);

            if(dist > maxDistancia){
                maxDistancia = dist;
                *p1 = p[i];
                *p2 = p[j];
            }
        }
    }
    
}

int main(){
    PONTOS pontos[N];
    PONTOS p1, p2; 
    
    for (int i = 0; i < N; i++){
        scanf('%f %f', &pontos[i].x, &pontos[i].y);
    }
    
    maior_distancia(pontos, &p1, &p2);
    
    printf("%f %f ", &p1, &p2);
}
