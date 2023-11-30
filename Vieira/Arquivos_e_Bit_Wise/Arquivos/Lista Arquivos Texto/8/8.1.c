#include <stdio.h>
#include <stdlib.h>

void merge_arquivos(char arquivo1, char arquivo2, char final) {
    FILE *arq1 = fopen(arquivo1, "r");
    FILE *arq2 = fopen(arquivo2, "r");
    FILE *merge = fopen(final, "w");

    if (arq1 == NULL || arq2 == NULL || merge == NULL) {
        fprintf(stderr, "Erro na abertura dos arquivos.\n");
        exit(1);
    }

    // Leitura do tamanho dos arquivos
    int tamanho1, tamanho2;
    fscanf(arq1, "%d", &tamanho1);
    fscanf(arq2, "%d", &tamanho2);

    // Vetores para armazenar os dados dos arquivos
    int *vetor1 = malloc(tamanho1 * sizeof(int));
    int *vetor2 = malloc(tamanho2 * sizeof(int));

    // Leitura dos valores dos arquivos para os vetores
    for (int i = 0; i < tamanho1; i++) {
        fscanf(arq1, "%d", &vetor1[i]);
    }

    for (int i = 0; i < tamanho2; i++) {
        fscanf(arq2, "%d", &vetor2[i]);
    }

    // Merge dos vetores ordenados
    int i = 0, j = 0;

    while (i < tamanho1 && j < tamanho2) {
        if (vetor1[i] < vetor2[j]) {
            fprintf(merge, "%d\n", vetor1[i]);
            i++;
        } else {
            fprintf(merge, "%d\n", vetor2[j]);
            j++;
        }
    }

    // Se ainda há elementos em um dos vetores
    while (i < tamanho1) {
        fprintf(merge, "%d\n", vetor1[i]);
        i++;
    }

    while (j < tamanho2) {
        fprintf(merge, "%d\n", vetor2[j]);
        j++;
    }

    // Liberar a memória alocada para os vetores
    free(vetor1);
    free(vetor2);

    // Fechar os arquivos
    fclose(arq1);
    fclose(arq2);
    fclose(merge);
}

int main() {
    merge_arquivos("primeiro1.txt", "segundo2.txt", "arquivoFinal.txt");

    return 0;
}
