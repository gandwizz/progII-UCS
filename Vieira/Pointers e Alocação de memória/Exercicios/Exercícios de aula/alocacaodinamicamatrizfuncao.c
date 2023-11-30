#include <stdio.h>
#include <stdlib.h>


int ** alocacaoDinamica( int linhas, int colunas){

    int **M = (int **)malloc(linhas * sizeof(int*));

    for (int i = 0; i < linhas; i++){
        M[i] = (int *)malloc(colunas * sizeof(int));
    }

    return M;

}