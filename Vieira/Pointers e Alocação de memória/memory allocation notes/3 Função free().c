#include <stdio.h>
#include <stdlib.h>


int main (void){
  int *p = (int *) malloc(sizeof(int));

  *p = 1000;

  free(p);

  printf("%i", *p);
}

/*
O malloc libera memória em duas condições: Quando o programa termina ou quando usa a função free();
Desalocar memória sempre que possível para otimizar

Free recebe qualquer tipo de ponteiro (void), portanto, pode passar qualquer tipo de ponteiro que ele libera memória

Ao fazer o Free, o ponteiro P ainda existe. Mas não há mais memória alocada. Apenas valores lixo 

*/