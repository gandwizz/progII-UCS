// 8) Implemente um programa que lê o nome e a pontuação de N candidatos (o valor de N é definido via diretiva #define) de um concurso e ao final exiba a listagem (nome e pontuação) dos candidatos com as duas maiores pontuações. Deve ser criada uma estrutura com os campos nome ( string ) e score ( float positivo) para armazenar os dados de um candidato. Também deve ser definida uma função que recebe um vetor de candidatos, que foram capturados na função main  e retorna os dois  candidatos com maiores pontuações.

// Protótipo da função:

// void maiores_pontuadores(CANDIDATO vet[N], CANDIDATO *c1, CANDIDATO *c2);


#include <stdio.h>
#include <stdlib.h>


#define N // numero de candidatos


typedef struct{
    char nome[100];
    float score;
}CANDIDATO;


void maiores_pontuadores(CANDIDATO vet[N], CANDIDATO *c1, CANDIDATO *c2){
    float primeiro = vet[0];
    float segundo = vet[1];

    for(int i = 0; i < N; i++){
        for(int j = i+1; j < N; j++){

            if(vet[i].score > vet[j].score ){

                if(vet[i].score > primeiro.score){
                    segundo = primeiro;

                    primeiro = vet[i]; 

                }else if(vet[i].score > segundo.score){
                    segundo = vet[i];
                }
            }

        }
    }

    *c1 = primeiro;
    *c2 = segundo;

}


int main(void){

    CANDIDATO candidatos[N];
    CANDIDATO *candidato1;
    CANDIDATO *candidato2;

    for(int i = 0; i < 5; i++){
        scanf("Digite o nome: %s", &candidatos[i].nome );
        scanf("Informe o Score: %d", &candidatos[i].score );
    }

    maiores_pontuadores(candidatos, &candidato1, &candidato2 );



}
