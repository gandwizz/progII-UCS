// ) (2.5 pontos) Faça um programa que leia um arquivo texto “entrada.txt” contendo uma lista de
// palavras e gere um arquivo “saida.txt” contendo todas as palavras que são palíndromas, ou seja, são
// iguais quando lidas do fim para o início ou do início para o fim (ex: “arara”);

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

    FILE * arq = fopen("entrada.txt", "rt");
    FILE * arqSaida = fopen("saida.txt", "rt");

    char linha[100];

    while(fgets(linha, sizeof(linha), arq) != NULL){

        int erro = 0, i, j;
        for ( i = 0, j= stlen(linha)-1 ; i < j; i++, j--){

            if( linha[0] != linha[j]) {
                erro = 1;
                break;
            }   

        }
        
        if(!erro){
            fprintf(arqSaida, "%s\n", linha);
        }
    }


    fclose(arq);
    fclose(arqSaida);
    return 0;
}
