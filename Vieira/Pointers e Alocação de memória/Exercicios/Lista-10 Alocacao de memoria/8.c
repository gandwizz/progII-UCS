// Faça uma função que receba como parâmetros um vetor com um conjunto de dados do tipo CLIENTE (e o seu tamanho) e data atual. A função deverá:

//     Calcular o número de clientes maiores de idade e retorne este valor através de um argumento;
//     Retornar um novo vetor de estruturas CLIENTE (alocado dinamicamente e com o tamanho exato) que contém todos os clientes maiores de idade;

// A função deve retornar NULL se não há houverem clientes maiores de idade. O protótipo da função é dado por:

// CLIENTE* maior_de_idade(CLIENTE *vet,  int num_clientes,  DATA atual,  int *num_maiores_idade)

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

typedef struct{
    int codigo;
    char nome[50];
    DATA nascimento;
} cliente;
typedef struct{
    int dia;
    int mes;
    int ano;
} DATA;

CLIENTE * maior_de_idade(CLIENTE *vet,  int num_clientes,  DATA atual,  int *num_maiores_idade){
    int i, k = 0;
    cliente *vetor;
    vetor = (cliente*) malloc(sizeof(cliente));
    for(i = 0; i < num_clientes; i++){
        if(atual.ano - vet[i].nascimento.ano > 18){
            vetor = (cliente*) realloc(vetor, (k+1)*sizeof(cliente)); //realoca o vetor para o tamanho de k+1 mas não é muito eficiente
            vetor[k] = vet[i];
            k++;
        }
    }
    *num_maiores_idade = k;
    return k > 0 ? vetor : NULL;
}