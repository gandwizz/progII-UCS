// Faça uma função que receba o nome de dois arquivos binários, e merge de dois arquivos texto ordenados, gerando um terceiro também ordenado. O protótipo da função é dado abaixo:

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge_arquivos(char arquivo1[50], char arquivo2[50], char final[50]){

    FILE *arq1=fopen(arquivo1,"rt");
    FILE *arq2=fopen(arquivo2,"rt");
    FILE *arqsai=fopen(final,"wt");

    int valor1,valor2;
    int res1=fscanf(arq1,"%d",&valor1);
    int res2=fscanf(arq2,"%d",&valor2);

    
    while (res1!=EOF || res2!=EOF) {
        if ((res1 == EOF && res2 != EOF) || (res1 !=EOF && res2 != EOF && valor2 < valor1)) { 
            fprintf(arqsai,"%d\n",valor2);
            res2=fscanf(arq2,"%d",&valor2);
        }else{
            fprintf(arqsai,"%d\n",valor1);
            res1=fscanf(arq1,"%d",&valor1);
        }
    }

    fclose(arqsai);
    fclose(arq1);
    fclose(arq2);
}


int main(){

    merge_arquivos("primeiroArquivo.txt", "segundoArquivo.txt", "mergeArquivos.txt");

    return 0;
}