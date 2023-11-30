#include <stdio.h>

int main(void){

  int x = 10;
  double y = 20.50;
  char z = 'a';

  //Observe que tem coisas diferentes nas declarações a seguir:
  int *pX;
  pX = &x; // O endereço do ponteiro X está apontando ao endreço de X
  
  int *ponteiroX = &x; //O valor do ponteiroX é igual ao endereço de memória de X
  /* Se o endereço de X = 1000 e o valor de X é 50 
    *ponteiroX = 1000;
    pX = 50;
  */



  double *pY = &y;
  char *pZ = &z; 

  printf("Enderexo x = %i - Valor x = %i", pX, *pX); // pX = o endereço, *pX = o valor 

}


/*
RESUMO

Acesso de memória e acesso de valor na memória

int *pX; 
px = &x
-- pX = ao endereço 
-- *pX = ao valor;



*/