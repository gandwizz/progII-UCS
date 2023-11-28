// Faça uma função que receba o nome de dois arquivos binários, e merge de dois arquivos texto ordenados, gerando um terceiro também ordenado. O protótipo da função é dado abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_arquivos(char arquivo1[50], char arquivo2[50], char final[50]){

    FILE *primeiro= fopen(arquivo1,"r");
    FILE *segundo = fopen(arquivo2,"r");
    FILE *merge = fopen(final,"w");

    if(primeiro == NULL || segundo == NULL || merge == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    // Pegar o tamanho dos arquivos
    int tamanho1, tamanho2;
    fscanf(primeiro, "%d", &tamanho1);
    fscanf(segundo, "%d", &tamanho2);

    //Vetores para armazenar os dados e unir
    int *arq1 = malloc(tamanho1 * sizeof(int));
    int *arq2 = malloc(tamanho2 * sizeof(int));
    int *arq3 = malloc((tamanho1 + tamanho2) * sizeof(int));

    int i, j;
    for(i = 0; i < tamanho1; i++){
        fscanf(primeiro, "%d", &arq1[i]);
        arq3[i] = arq1[i];
    }

    for(j = 0; j < tamanho2; j++){
        fscanf(segundo, "%d", &arq2[j]);
        arq3[tamanho1+j] = arq2[j];
    }

    for(int k = 0; k < tamanho1+tamanho2; k++){
        for(int l = k+1; l < tamanho1+tamanho2; l++){
            if(arq3[k] < arq3[l]){
                int aux = arq3[k];
                arq3[k] = arq3[l];
                arq3[l] = aux;
            }
        }
        fprintf(merge, "%d\n", arq3[k]);
    }

    fclose(primeiro);
    fclose(segundo);
    fclose(merge);

};


int main(){

    merge_arquivos("primeiroArquivo.txt", "segundoArquivo.txt", "mergeArquivos.txt");

    return 0;
}