#include <stdio.h>
#include <stdlib.h>

unsigned int intersecao (unsigned int c1, unsigned int c2) {
	unsigned int res = c1&c2;
	return res;
}

unsigned int uniao(unsigned int c1, unsigned int c2) {
	unsigned int res = c1|c2;
	return res;
}

unsigned int diferenca(unsigned int c1, unsigned int c2)  {
	unsigned int res = c1&(~c2);
	return res;
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
   	unsigned int c1 = 0;
   	unsigned int c2 = 0;
   	
   	mostrabin(c1);
   	mostrabin(c2);
   	
   	int valor;
   	int qtd = 0;
   	
   	printf("\n\ninserir quantos valores c1: \n");
	scanf("%d",&qtd);
	
	for (int i=0; i<qtd; i++) {
		printf("\n\ninsere valor %d: \n",i);
		scanf("%d",&valor);	
		insere(&c1, valor);
			
		mostrabin(c1);
	}	
	
	printf("\n\ninserir quantos valores c2: \n");
	scanf("%d",&qtd);
	
	for (int i=0; i<qtd; i++) {
		printf("\n\ninsere valor %d: \n",i);
		scanf("%d",&valor);	
		insere(&c2, valor);
			
		mostrabin(c2);
	}	
		
	printf("\n\nintersecao: \n");
	printf("c1: \n");
	mostrabin(c1);
	printf("\nc2: \n");
	mostrabin(c2);
	printf("\nresposta: \n");
	unsigned int resposta = intersecao(c1,c2);
	mostrabin(resposta);
	
	printf("\n\nuniao: \n");
	printf("c1: \n");
	mostrabin(c1);
	printf("\nc2: \n");
	mostrabin(c2);
	printf("\nresposta: \n");
	unsigned int resposta2 = uniao(c1,c2);
	mostrabin(resposta2);
	
	printf("\n\ndiferenca: \n");
	printf("c1: \n");
	mostrabin(c1);
	printf("\nc2: \n");
	mostrabin(c2);
	printf("\nresposta: \n");
	unsigned int resposta3 = diferenca(c1,c2);
	mostrabin(resposta3);


	return 0;
}
