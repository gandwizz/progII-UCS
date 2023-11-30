#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void contadorHolmes(char nome_arquivo[10]){

    FILE *arquivo = fopen(nome_arquivo,"r"); 
    

    if(arquivo == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    char linha[1000];
    int contador = 0;


    while(fgets(linha, sizeof(linha), arquivo) != NULL){

        if(strstr(linha, "Holmes") != NULL || strstr(linha, "holmes") != NULL){
            contador++;
        }
    }

    printf("Valor total que aparece a palavra Holmes:  %d\n", contador);

    fclose(arquivo);
};


int main(){

    contadorHolmes("Baskervilles.txt");

    return 0;
}