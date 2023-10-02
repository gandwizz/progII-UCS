// 5) Na Teoria de Sistemas, define-se como elemento minimax de uma matriz o menor elemento da linha em que se encontra o maior elemento da matriz. Faça uma função que receba como parâmetro uma matriz A[5][5] e retorne o valor do elemento minimax, bem como a linha e coluna onde ocorreu.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int matriz(int *st[5][5], int *minimax, int *coluna, int *linha){

    *minimax = st[0][0];
    *coluna = 0;
    *linha = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(st[i][j] < minimax){
                *linha = i;
                *coluna = i;
                *minimax = st[i][j];
            } 
        }
    }

}