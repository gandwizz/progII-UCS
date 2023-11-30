#include <stdio.h>


int main(void){

  int x = 10;
  int *pX = &x; 


  int vetor[3] = {1,2,3};
  int *pVetor = vetor; // n precisa do '&' p indicar o endereço. Ele irá apontar para o primeiro elemento do vetor.
  int *pVetor = &vetor[0]; // indica o endereço do elemento da posição 0 
  
}