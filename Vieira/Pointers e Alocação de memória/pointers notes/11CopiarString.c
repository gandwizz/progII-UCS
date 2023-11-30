#include <stdio.h>

void copiarString(char *copiarDaqui, char *colarAqui){ //recebe os ponteiros aqui

  //É feito caractér por caracter
  while(*copiarDaqui != '\0'){
    *colarAqui = *copiarDaqui;
    copiarDaqui++; //avança um endereço do vetor pra frente;
    colarAqui++; //pra não colocar o mesmo caracter no mesmo lugar
  }
  *colarAqui = '\0'; //adicionar o caracter nulo no final da string;
}

int main(void){
  
  char string1[] = "No idea to a phrase!";
  char string2[20];

  copiarString(string1, string2); //passando dois endereços de memórias de duas strings

  printf("%s\n", string2);
}