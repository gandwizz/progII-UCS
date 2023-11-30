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
		printf("%d", conjunto >> i&1);
	}
}

void rota_esq(unsigned int *conjunto) {
    *conjunto=(*conjunto<<1)|(*conjunto>>31);
}

void rota_dir(unsigned int *conjunto) {
    *conjunto=(*conjunto>>1)|(*conjunto<<31);
}

int operacao (unsigned int *c1, unsigned int *c2) {
	system("@cls||clear");

    printf("\n\nc1: \n");
	mostrabin(*c1);
	printf("\nc2: \n");
	mostrabin(*c2);
    
    int op = 0;
    printf("\n\n Selecione operacao deseja realizar:\n");
    
    printf("\n 1. Inserir em um dos conjuntos \n");
    printf(" 2. Remover de um dos conjuntos \n");
    printf(" 3. Teste em um dosconjunto \n");
    printf(" 4. Mostrar conjunto \n");
    printf(" 5. Intersecao entre conjuntos \n");
    printf(" 6. Uniao entre conjuntos \n");
    printf(" 7. Diferença entre conjuntos \n");
    printf(" 8. Rotacionar para esquerda \n");
    printf(" 9. Rotacionar para direita \n");
    printf(" 10. SAIR \n");
    scanf("%d",&op);

	int continua;
	int conjunto = 0;
	int qtd;

	if (op == 1){

		printf("\n Em qual conjunto deseja inserir ? \n");
		printf("\n 1. Conjunto 1 \n");
		printf("\n 2. Conjunto 2 \n");
		scanf("%d",&conjunto);

		int valor;
		printf("\n\ninserir quantos valores: \n");
		scanf("%d",&qtd);

		if(conjunto == 1) {
				int i = 0;				
				for (i=0; i<qtd; i++){
					printf("\n\ninsere valor %d: \n",i);
					scanf("%d",&valor);	
					insere(c1, valor);
					mostrabin(*c1);
				}
				
				return 1;
				
		} else if (conjunto == 2) {

				int i;
				for (i=0; i<qtd; i++) {
					printf("\n\ninsere valor %d: \n",i);
					scanf("%d",&valor);	
					insere(c2, valor);
					mostrabin(*c2);
				}	
				
				return 1;

		} else {
			system("@cls||clear");
			printf(" \n Conjunto Inválido \n");
			return 1;
		}

	} else if (op == 2) {

		printf("\n De qual conjunto deseja Remover ? \n");
		printf("\n 1. Conjunto 1 \n");
		printf("\n 2. Conjunto 2 \n");
		scanf("%d",&conjunto);

		int valor;
		printf("\n\nRemover quantos valores: \n");
		scanf("%d",&qtd);

		if(conjunto == 1) {
			int i = 0;
			
			for (i=0; i<qtd; i++){
				printf("\n\nremover valor %d: \n",i);
				scanf("%d",&valor);	
				remover(c1, valor);
				mostrabin(*c1);
			}
			
			return 1;
				
		} else if (conjunto == 2) {
				
			int i;
			for (i=0; i<qtd; i++) {
				printf("\n\nremover valor %d: \n",i);
				scanf("%d",&valor);	
				remover(c2, valor);
				mostrabin(*c2);
			}	
			
			return 1;

		} else {
			system("@cls||clear");
			printf(" \n Conjunto Inválido \n");
			return 1;
		}

	} else if (op == 3) {
		printf("\n De qual conjunto deseja testar ? \n");
		printf("\n 1. Conjunto 1 \n");
		printf("\n 2. Conjunto 2 \n");
		scanf("%d",&conjunto);

		int valor;
		printf("\n\nTestar quantos valores: \n");
		scanf("%d",&qtd);

		if(conjunto == 1) {
			int i = 0;
			
			for (i=0; i<qtd; i++){
					int vtesta;
					printf("\n\nvalor para testar: \n");
					scanf("%d",&vtesta);
					int res = testa(*c1, vtesta);	
					printf("\n\nres: %d \n", res);	
			}
			
			return 1;
				
		} else if (conjunto == 2) {
				
			int i;
			for (i=0; i<qtd; i++){
					int vtesta;
					printf("\n\nvalor para testar: \n");
					scanf("%d",&vtesta);
					int res = testa(*c2, vtesta);	
					printf("\n\nres: %d \n", res);	
			}
			
			return 1;

		} else {
		    system("@cls||clear");

			printf(" \n Conjunto Inválido \n");
			return 1;
		}

	} else if (op == 4) {
		printf("\n De qual conjunto deseja mostrar ? \n");
		printf("\n 1. Conjunto 1 \n");
		printf("\n 2. Conjunto 2 \n");
		scanf("%d",&conjunto);

		if(conjunto == 1) {
			mostra(*c1);
			printf("\n Digite qualquer tecla para continuar \n");	
			scanf("%d", &continua);		
			return 1;
				
		} else if (conjunto == 2) {
			mostra(*c2);
			scanf("%d", &continua);		
			return 1;	

		} else {
		    system("@cls||clear");
			printf("\n Digite qualquer tecla para continuar \n");
			printf(" \n Conjunto Inválido \n");
			return 1;
		}

	} else if (op == 5) {

		unsigned int resInter = intersecao(*c1,*c2);
		printf("\n\n c1: \n");
		mostrabin(*c1);
		printf("\n c2: \n");
		mostrabin(*c2);
		printf("\nintersecao: \n");
		mostrabin(resInter);

		printf("\n Digite qualquer tecla para continuar \n");	
		scanf("%d", &continua);		
		return 1;


	} else if (op == 6) {

		unsigned int resUniao = uniao(*c1,*c2);
		printf("\n\n c1: \n");
		mostrabin(*c1);
		printf("\n c2: \n");
		mostrabin(*c2);
		printf("\nUnião: \n");
		mostrabin(resUniao);

		printf("\n Digite qualquer tecla para continuar \n");	
		scanf("%d", &continua);		
		return 1;

	} else if (op == 7) {

		unsigned int resDif = diferenca(*c1,*c2);
		printf("\n\n c1: \n");
		mostrabin(*c1);
		printf("\n c2: \n");
		mostrabin(*c2);
		printf("\nDiferença: \n");
		mostrabin(resDif);

		printf("\n Digite qualquer tecla para continuar \n");	
		scanf("%d", &continua);		
		return 1;

	}  else if (op == 8) {

		printf("\n Qual conjunto deseja rotacionar ? \n");
		printf("\n 1. Conjunto 1 \n");
		printf("\n 2. Conjunto 2 \n");
		scanf("%d",&conjunto);

		printf("\n\nrotacionar quantas posições: \n");
		scanf("%d",&qtd);

		if(conjunto == 1) {
				int i = 0;				
				for (i=1; i<=qtd; i++){
					rota_esq(c1);
					printf("\n conjunto:");
					mostrabin(*c1);
				}

				printf("\n Digite qualquer tecla para continuar \n");	
				scanf("%d", &continua);		
				return 1;
				
		} else if (conjunto == 2) {

				int i = 0;				
				for (i=0; i<qtd; i++){
					rota_esq(c2);
					printf("\n conjunto:");
					mostrabin(*c2);
				}

				printf("\n Digite qualquer tecla para continuar \n");	
				scanf("%d", &continua);		
				return 1;

		} else {
			system("@cls||clear");
			printf(" \n Conjunto Inválido \n");
			return 1;
		}

	}  else if (op == 9) {

		printf("\n Qual conjunto deseja rotacionar ? \n");
		printf("\n 1. Conjunto 1 \n");
		printf("\n 2. Conjunto 2 \n");
		scanf("%d",&conjunto);

		printf("\n\nrotacionar quantas posições: \n");
		scanf("%d",&qtd);

		if(conjunto == 1) {
				int i = 0;				
				for (i=1; i<=qtd; i++){
					rota_dir(c1);
					printf("\n conjunto:");
					mostrabin(*c1);
				}

				printf("\n Digite qualquer tecla para continuar \n");	
				scanf("%d", &continua);		
				return 1;
				
		} else if (conjunto == 2) {

				int i = 0;				
				for (i=0; i<qtd; i++){
					rota_dir(c2);
					printf("\n conjunto:");
					mostrabin(*c2);
				}

				printf("\n Digite qualquer tecla para continuar \n");	
				scanf("%d", &continua);		
				return 1;

		} else {
			system("@cls||clear");
			printf(" \n Conjunto Inválido \n");
			return 1;
		}

	} else if (op == 10) {
		return 0;
	} else {
	    system("@cls||clear");
		printf(" \n Operação Inválida!!!!!! \n");
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
}
