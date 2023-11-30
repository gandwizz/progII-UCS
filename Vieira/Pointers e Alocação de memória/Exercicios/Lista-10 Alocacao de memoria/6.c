// 6) Crie uma função que receba como parâmetros dois vetores de inteiros: x1 e x2 e as suas respectivas quantidades de elementos: n1 e n2. A função deverá retornar um ponteiro para um terceiro vetor, x3, alocado dinamicamente, contendo a união de x1 e x2 e usar o ponteiro qtd para retornar o tamanho de x3. Assuma que em um mesmo  vetor não haverá valores repetidos, mas um valor contido em x1 poderá também estar contido em x2.  Nesse caso, apenas uma ocorrência deve ser colocada em x2.   Sendo x1={1,3,5,6,7} e x2={1,3,4,6,8}, x3 irá conter {1,3,5,6,7,4,8}. O protótipo da função é dado por:
//int* uniao(int *x1, int *x2, int n1, int n2, int* qtd)

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int* uniao(int *x1, int *x2, int n1, int n2, int* qtd){
    int *x3 = (int*)malloc((n1+n2) * sizeof(int)); 

    // Colocar os elementos de x1 em x3
    for(int i = 0; i<n1; i++){
        x3[i] = x1[i];
    }
    int k = n1;  // Variável auxiliar para controlar a posição em x3

    // Verificar e adicionar os elementos de x2 que não estão em x1 para x3
    for (int i = 0; i < n2; i++) {
        int esta = 0;
        for (int j = 0; j < n1; j++) {
            if (x2[i] == x1[j]) {
                esta = 1;
                break;
            }
        }
        if (!esta) {
            x3[k] = x2[i];
            k++;
        }
    }

    // Atualizar a quantidade de elementos em x3
    *qtd = k;

    return x3;
}

int main() {
    int x1[] = {1, 3, 5, 6, 7};
    int x2[] = {1, 3, 4, 6, 8};
    int n1 = 5;
    int n2 = 5;
    int qtd;

    int *x3 = uniao(x1, x2, n1, n2, &qtd);

    printf("Uniao: ");
    for (int i = 0; i < qtd; i++) {
        printf("%d ", x3[i]);
    }
    printf("\n");

    // Libera a memória alocada
    free(x3);

    return 0;
}