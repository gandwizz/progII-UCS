#include <stdio.h>
#include <stdlib.h>


int main (void){

  int *p = (int *) calloc( 10, sizeof(int)); // alocando 10 espaços de memória de tamanho int --> 5 * 4bytes = 20bytes
  int *p = (int *) malloc( 10 * sizeof(int)); // Aloca a mesma quantidade, mas tem sujeira no bloco alocado


  int *p = (int *)calloc(5 *sizeof(int));

  //como trocar os valores dos blocos 
  *p = 10; // troca o valor do primeiro bloco de int
  *(p+1) = 10;// troca o segundo valor.


  for(int i = 0; i<10; i++){
    printf("Endereço de p%i = %p |valor de p%i = %i\n", i, &p[i], i, *(p+i))
  }

  printf("%i", p[1]);
}

/*
  Calloc tbm aponta p um ponteiro void, portanto, necessário colocar o cast


  CALLOC INICIALIZA O VALOR NO BLOCO DE MEMÓRIA ALOCADO = 0
*/