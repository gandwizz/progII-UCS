#include <stdio.h>
#include <stdlib.h>


int main(void){

//malloc = memory allocation: aloca um bloco de memória de um respectivo tamanho
// a função retorna um ponteiro com o endereço de onde foi alocado a memória
// o malloc retorna um ponteiro do tipo VOID !!!! VAI DAR CONFLITO tem q usar cast

  int *p = malloc( sizeof(int) ); 
  int *p = malloc( 10* sizeof(int) ); // alocar para um vetor de tamanho 10 por exemplo 

  //como o malloc retorna void, vms utilizar um casting

  int *p = (int*)malloc( sizeof(int) ); 
  int *p = (int*)malloc( 10* sizeof(int) ); // alocar para um vetor de tamanho 10 por exemplo 

  *p = 1000; // se tu não atribuir valor, se tiver lixo de memória onde foi alocado, vai ficar lixo!! Essa é a diferença entre o calloc e o malloc



  size_t; // variavel  que assume valores positivos necessariamente e inteiros --> garantir que não será informado no malloc um valor negativo !!

}

/*
  O sistema operacional antes do tempo de execução já aloca as memórias, mas há casos que isso não acontece.
  Portanto, é necessário alocar a quantidade de memória necessária para o programa rodar!!!!


  Se o malloc não conseguir alocar memória, ele retorna null! 
*/