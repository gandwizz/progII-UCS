// 5) Crie uma função que receba como parâmetros dois vetores de inteiros: x1 e x2 e as suas respectivas quantidades de elementos: n1 e n2. A função deverá retornar um ponteiro para um terceiro vetor, x3, alocado dinamicamente, contendo a intersecção de x1 e x2 e usar o ponteiro qtd para retornar o tamanho de x3. Assuma que em um mesmo  vetor não haverá elementos repetidos. Sendo x1={1,3,5,6,7} e x2={1,3,4,6,8}, x3 irá conter {1,3,6}. O protótipo da função é dado por:

// int* interseccao(int *x1, int *x2, int n1, int n2, int* qtd)

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>


int* interseccao(int *x1, int *x2, int n1, int n2, int* qtd){
    int *x3 = (int*)malloc((n1+n2) * sizeof(int)); //vetor x3 alocado

    // qtd = tamanho de x3

    int contador = 0;
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            if(x1[i] == x2[j]){
                x3[contador] = x1[i];
                contador++;
            }
        }
    }

    *qtd = contador;
    return x3;
}


int main() {
    int x1[] = {1, 3, 5, 6, 7};
    int x2[] = {1, 3, 4, 6, 8};
    int n1 = 5;
    int n2 = 5;
    int qtd;

    int *x3 = interseccao(x1, x2, n1, n2, &qtd);

    printf("Interseccao: ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", x3[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(x3);

    return 0;
}