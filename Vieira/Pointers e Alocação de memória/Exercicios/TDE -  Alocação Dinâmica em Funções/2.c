// 2) Fazer uma função que retorne o apontador para uma string contendo apenas os dígitos da string informada como parâmetro.
// Protótipo: char *digitos(char *s)

#include <stdio.h>
#include <stdlib.h>

char *digitos(char *s){
  //recebe uma string que pode conter qualquer coisa "AbCdE1231908"
  
  //obter o valor total de digitos para alocar um numero exato
  int count = 0;
  for(int i = 0; i < strlen(s); i++){
    if( s[i] >= '0' && s[i] <= '9' ){
      count++;
    }
  }

  char *str = (char *) malloc( (count+1) * sizeof(char));
  int posicaoArray = 0;
  for(int i = 0; i < strlen(s); i++){
    if( s[i] >= '0' && s[i] <= '9' ){
      str[posicaoArray] = s[i]; 
      posicaoArray++;
    }
  }
  str[posicaoArray] = '\0';
  return str;
}
