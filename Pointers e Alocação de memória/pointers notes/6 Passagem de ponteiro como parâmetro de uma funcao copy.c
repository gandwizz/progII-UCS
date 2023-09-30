#include <stdio.h>

// o int x é uma variável independente de teste. É uma cópia 
// essa função faz uma copia de um int a cada vez que é chamada, ou seja, consome muita memória. 
void testeVariavel(int x){ 
  ++x;
}


  // quando passamos assim, o int *pX, esta recebendo o endereço de memória da variável teste. 
  // ou seja, vai alterar o valor oficial!!!!
  // Econômia de memória!!
void testePonteiro(int *pX){ 
  ++*pX;
}

int main(void){
  int teste = 1;
  int *pTeste = &teste;

  testeVariavel(teste);
  testePonteiro(pTeste); // passa o endereço de memória

  printf("%d\n", teste);

}

/*
As funções que tem como parâmetro um ponteiro, recebem um endereço de memória, ou seja, 
quando chamar a função, precisa passar o endereço como parâmetro, e não seu valor.

*/