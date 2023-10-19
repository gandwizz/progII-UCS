// 4) Faça uma função que receba como parâmetro uma matriz M[5][5] e retorne o maior valor existente na matriz, bem como a linha e coluna onde o valor ocorre.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void matriz(int *st[5][5], int *maior, int *coluna, int *linha){

    *maior = st[0][0];
    *coluna = 0;
    *linha = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(st[i][j] > maior){
                *linha = i;
                *coluna = j;
                *maior = st[i][j];
            } 
        }
    }

}