#include <stdio.h>
#include <stdlib.h>

unsigned int intersecao (unsigned int c1, unsigned int c2) {
	unsigned int res = c1&c2;
}

unsigned int uniao(unsigned int c1, unsigned int c2) {
	unsigned int res = c1|c2;
}

unsigned int diferen¸ca(unsigned int c1, unsigned int c2)  {
	unsigned int res = c1&(~c2);
}

void mostra (int conjunto){
	int i;
	
	printf("\n\nconjunto: \n");
	for (i=0;i<=31;i++) {		
		if (conjunto >> i&1) {			
			printf("%d \n", i);
		}
		
	}
}

void remove (unsigned int *conjunto, int valor) {
	unsigned int mascara = 1<<valor;	
	*conjunto &= (~mascara);
}

int testa (unsigned int conjunto, int valor) {
	unsigned int res = conjunto>>valor&1;
	return res;
}

void insere(unsigned int *conjunto, int valor ) {
	unsigned int mascara = 1<<valor;	
	*conjunto |= mascara;
}

void mostrabin(unsigned int conjunto){
	int i;
	for (i=31;i>=0;i--) {
		printf("%d", conjunto >> i&1);
	}
}


int main(){
   	unsigned int c = 0;
   	
   	mostrabin(c);
   	int valor;
   	int qtd = 0;
   	
   	printf("\n\ninserir quantos valores: \n");
	scanf("%d",&qtd);
	
	for (int i=0; i<qtd; i++) {
		printf("\n\ninsere valor %d: \n",i);
		scanf("%d",&valor);	
		insere(&c, valor);
			
		mostrabin(c);
	}	
		
	int vtesta;
	printf("\n\nvalor para testar: \n");
	scanf("%d",&vtesta);
	int res = testa(c, vtesta);	
	printf("\n\nres: %d \n", res);	
	
	int vrem;
	printf("\n\nvalor para remover: \n");
	scanf("%d",&vrem);
	remove(&c, vrem);	
	mostrabin(c);
	
	mostra(c);

	return 0;
}
