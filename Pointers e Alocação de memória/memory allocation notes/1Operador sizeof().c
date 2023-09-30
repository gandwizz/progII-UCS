#include <stdio.h>
#include <stdlib.h>


struct x{
  int a;
  int b;
  int c;
}


int main(void){

  int x;
  double y;

  // Calcular um tamanho, em bytes, de um tipo de dado

  sizeof(x); // 4 bytes = 8bits --> 4bytes = tamanho do int
  sizeof(y); // 8 bytes = 16bits --> 8bytes = tamanho do double

  sizeof(short);
  sizeof(int);
  sizeof(bool);
  sizeof(float);
  //... etc

  int vetor[10];

  sizeof(vetor); // 4bytes * tamanho do vetor (10) = 40bytes

  struct x estrutura;

  sizeof(estrutura); // Como tem 3 ints: 3*4bytes = 12bytes

}