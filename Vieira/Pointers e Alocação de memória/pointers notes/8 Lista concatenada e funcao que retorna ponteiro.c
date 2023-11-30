#include <stdio.h>

struct lista{
  int valor;
  struct lista *proximo; 
};

struct lista *procurarValor( struct lista *pLista, int valor){ //retorna um endereço de memória de uma struct lista

    while( pLista != (struct lista *)0 ){
      
      if( pLista->valor == valor ){
        return(pLista); //retorna o endereço de memória
      }else{
        pLista = pLista->proximo;
      }

    }

    return (struct lista*)0;
};


int main(void){

  struct lista m1,m2,m3;
  struct lista *resultado, *gancho = &m1;
  int valor;

  m1.valor = 5;
  m2.valor = 10;
  m3.valor = 20;


  m1.proximo = &m2;
  m2.proximo = &m3;
  m3.proximo = 0;

  scanf("%d", &valor);


  resultado = procurarValor( gancho, valor);

  if( resultado == (struct lista*)0){
    printf("Valor n encontrado");

  }else{
    printf("%d\n", resultado->valor);
  }


}

/*

*/