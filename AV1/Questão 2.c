/**
    2) linhas desta matriz até que na primeira linha fique a linha que contem maior quantidade de números zeros, na segunda linha a que contém a segunda maior quantidade de numeros zeros, ..., e finalmente na última linha que contem a menor quantidade de números zeros. Por fim escreva a matriz resultante. 
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int contarZeros(int linha[4]){
    int zeros = 0;
    for (int i = 0; i < 4; i++)
    {
        if(linha[i] == 0 ){
            zeros++;
        }
    }
    return zeros;
}


void classificarLinhas(int matriz[][4]){

    for (int i = 0; i < 4-1; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if( contarZeros(matriz[i]) < contarZeros(matriz[j])){
                //Troca as linhas
                for (int k = 0; k < 4; k++) {
                    int aux[4];
                    aux[k] = matriz[i][k];
                    matriz[i][k] = matriz[j][k];
                    matriz[j][k] = aux[k];
                }
            }
        }
        
    }
}

int main(void){

    int matriz[4][4] = {
        {0, 1, 2, 5},
        {0, 1, 0, 0},
        {0, 0, 0, 0},
        {2, 0, 3, 0}
    };

    classificarLinhas(matriz);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d", matriz[i][j]);
        }        
        printf("\n");
    }
}


