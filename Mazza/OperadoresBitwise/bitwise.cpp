#include <stdio.h>
#include <stdlib.h>

unsigned int intersecao (unsigned int c1, unsigned int c2) {
	unsigned int res = c1&c2;
}

unsigned int uniao(unsigned int c1, unsigned int c2) {
	unsigned int res = c1|c2;
}

unsigned int diferenca (unsigned int c1, unsigned int c2)  {
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

void remover (unsigned int *conjunto, int valor) {
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
		printf(" %d", conjunto >> i&1);
	}
}

void rota_esq(unsigned int *c) {
    *c=(*c<<1)|(*c>>15);
}

void rota_dir(unsigned int *c) {
    *c=(*c>>1)|(*c<<15);
}

void operacao (unsigned int *c1, unsigned int *c2) {
    printf("\n\n c1: \n");
	mostrabin(*c1);
	printf("\n c2: \n");
	mostrabin(*c2);
    
    int op = 0;
    printf("\n Selecione operacao deseja realizar:\n");
    
    printf("\n 1. Inserir em um dos conjuntos \n");
    printf(" 2. Remover de um dos conjuntos \n");
    printf(" 3. Teste em um dosconjunto \n");
    printf(" 4. Inserir em conjunto \n");
    printf(" 5. Mostrar conjunto \n");
    printf(" 6. Intersecao entre conjuntos \n");
    printf(" 7. Uniao entre conjuntos \n");
    printf(" 8. Diferença entre conjuntos \n");
    scanf("%d",&op);

	if (op == 1){
		int conjunto = 0;
		printf("\n Em qual conjunto deseja inserir ? \n");
		printf("\n 1. Conjunto 1 \n");
		printf("\n 1. Conjunto 2 \n");
		scanf("%d",&conjunto);

		if(conjunto == 1) {
				printf("\n\ninserir quantos valores: \n");
				scanf("%d",&qtd);
				
				for (int i=0; i<qtd; i++) {
				printf("\n\ninsere valor %d: \n",i);
				scanf("%d",&valor);	
				insere(&c1, valor);
				mostrabin(c1);
	}
		} else if (conjunto == 2) {
				printf("\n\ninserir quantos valores c2: \n");
				scanf("%d",&qtd2);
				
				for (int i=0; i<qtd2; i++) {
					printf("\n\ninsere valor %d: \n",i);
					scanf("%d",&valor2);	
					insere(&c2, valor2);
					mostrabin(c2);
				}	
		} else {
			printf(" \n Conjunto Inválido \n");
			return 1;
		}

	} else if (op == 2) {

	} else if (op == 3) {

	} else if (op == 4) {

	} else if (op == 5) {

	} else if (op == 6) {

	} else if (op == 7) {

	} else if (op == 8) {

	} else {
		printf(" \n Operação Inválida \n");
		return 1;
	}
    
}


int main() {
   	unsigned int c = 0;
	unsigned int c2 = 0;

	int permanece = 1;

	while (permanece == 1) {
		permanece = operacao(&c,&c2);
	}

    return 0;
   	
   	// mostrabin(c);
   	
//   	int valor;
//   	int qtd = 0;
   	
//   	printf("\n\ninserir quantos valores: \n");
// 	scanf("%d",&qtd);
	
// 	for (int i=0; i<qtd; i++) {
// 		printf("\n\ninsere valor %d: \n",i);
// 		scanf("%d",&valor);	
// 		insere(&c, valor);
// 		mostrabin(c);
// 	}
   	
//   	// mostrabin(c2);
   	
//   	int valor2;
//   	int qtd2 = 0;
   	
//   	printf("\n\ninserir quantos valores c2: \n");
// 	scanf("%d",&qtd2);
	
// 	for (int i=0; i<qtd2; i++) {
// 		printf("\n\ninsere valor %d: \n",i);
// 		scanf("%d",&valor2);	
// 		insere(&c2, valor2);
// 		mostrabin(c2);
// 	}	
	
// 	unsigned int resInter = intersecao(c,c2);
// 	printf("\n\n c1: \n");
// 	mostrabin(c);
// 	printf("\n c2: \n");
// 	mostrabin(c2);
// 	printf("\nintersecao: \n");
// 	mostrabin(resInter);
	
// 	unsigned int resUniao = uniao(c,c2);
// 	printf("\n\n c1: \n");
// 	mostrabin(c);
// 	printf("\n c2: \n");
// 	mostrabin(c2);
// 	printf("\nUnião: \n");
// 	mostrabin(resUniao);
	
// 	unsigned int resDif = diferenca(c,c2);
// 	printf("\n\n c1: \n");
// 	mostrabin(c);
// 	printf("\n c2: \n");
// 	mostrabin(c2);
// 	printf("\nDiferença: \n");
// 	mostrabin(resDif);
	
	
	
		
// 	int vtesta;
// 	printf("\n\nvalor para testar: \n");
// 	scanf("%d",&vtesta);
// 	int res = testa(c, vtesta);	
// 	printf("\n\nres: %d \n", res);	
	
// 	int vrem;
// 	printf("\n\nvalor para remover: \n");
// 	scanf("%d",&vrem);
// 	remover(&c, vrem);	
// 	mostrabin(c);
	
// 	mostra(c);

	return 0;
}
