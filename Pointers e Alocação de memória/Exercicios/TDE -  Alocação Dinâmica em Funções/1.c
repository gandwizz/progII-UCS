// 1) Fazer uma função que retorne o apontador para uma string contendo as n primeiras letras maiúsculas. Caso n seja maior que 26, copie novamente as letras maiúsculas até atingir o valor de n.
// Protótipo: char *letras(int n)

#include <stdio.h>
#include <stdlib.h>

char *letras(int n){

  char *str = (char *) malloc((n+1) * sizeof(char));
  for(int i = 0; i < n; i++){
    str[i] = 'A' + (i % 26); 
  }

  str[n] = '\0';
  return str;
}


int main() {
  int n;
  printf("Digite o número de letras desejado: ");
  scanf("%d", &n);

  char *resultado = letras(n);

  printf("As primeiras %d letras maiúsculas são: %s\n", n, resultado);

  // Libera a memória alocada para a string
  free(resultado);

  return 0;
}