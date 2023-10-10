// 3) Fazer uma função que retorne o apontador para um vetor de inteiros contendo os n primeiros números primos.
// Protótipo: int *primos(int n)

#include <stdio.h>
#include <stdlib.h>

int ehPrimo(int num){
  if(num <=1 ) return 0; //caso n for primo

  /*
   i*i < num é uma otimização na busca dos numeros primos. Não é necessário verificar todos os números até num para encontrar o divisor. 
  Basta verificar até a raiz quadrada de num. Se houver um divisor maior que a raiz quadrada de num, então já teríamos encontrado um divisor menor que a raiz quadrada.

  Por exemplo, se queremos verificar se 100 é primo, sabemos que os possíveis divisores estarão entre 2 e a raiz quadrada de 100, ou seja, entre 2 e 10. Se não encontrarmos nenhum divisor até 10, não encontraremos depois disso também.
  
  */
  for(int i = 2; i*i < num; i++ ){
    if(num % i == 0) return 0;
  }

  return 1; //caso for primo
}

int *primos(int n){

  int *primos = (int *)malloc(n * sizeof(int));
  int posicaoPrimos = 0;
  int i = 2;

  while(posicaoPrimos < n){
    if( ehPrimo(i) ){
      primos[posicaoPrimos] = i;
      posicaoPrimos++;
    }
    i++;
  }
  return primos;
}

int main() {
  int n;
  printf("Digite o número de primos desejado: ");
  scanf("%d", &n);

  int *resultado = primos(n);

  printf("Os primeiros %d números primos são: ", n);
  for (int i = 0; i < n; i++) {
    printf("%d ", resultado[i]);
  }
  printf("\n");

  // Libera a memória alocada para o vetor de primos
  free(resultado);

  return 0;
}
