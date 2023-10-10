// 4) Fazer uma função que retorne em um vetor os números pares que estão em uma matriz de 10 linhas por 15 colunas. Implementar de formas distintas, para cada protótipo abaixo:
// Protótipo1: void copia_num_pares(int m[10][15], int **v, int *qtd)
// Protótipo2: int *num_pares(int m[10][15], int *qtd)
// Em ambos os casos acima, a função deverá alocar o espaço necessário para armazenar esses números no vetor.


#include <stdio.h>
#include <stdlib.h>


//Essa função altera os valores no ponteiro diretamente. 
void copia_num_pares(int m[10][15], int **v, int *qtd){
  int *v = (int*)malloc((10 * 15) * sizeof(int*)); 
  int posicaoV = 0;

  for(int i=0; i < 10; i++){
    for(int j=0; j < 15; j++){
      if(m[i][j] % 2 == 0){
        (*v)[posicaoV]= m[i][j];
        posicaoV++;
      }
    }
  }

  *qtd = posicaoV;
}

//Nessa função, é necessário alocar um vetor e retorna-lo 
int *num_pares(int m[10][15], int *qtd){
  int *v = (int*)malloc((10 * 15) * sizeof(int*)); 
  int posicaoV = 0;

  for(int i=0; i < 10; i++){
    for(int j=0; j < 15; j++){
      if(m[i][j] % 2 == 0){
        v[posicaoV]= m[i][j];
        posicaoV++;
      }
    }
  }

  v = realloc(v, posicaoV * sizeof(int));

  return v;
}