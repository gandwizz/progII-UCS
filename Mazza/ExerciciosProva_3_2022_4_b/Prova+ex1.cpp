#include <stdio.h>

//int eh_primo(int num) {
//	if(num < 2) return 1;
//	
//	for (int i=2; i*i<=num; i++) {
//		if(num % i == 0) return 0;
//	}
//	
//	return 1;
//}

typedef struct venda {int dia; int mes; int ano; int quantidade;} tvenda;
typedef struct mes {int mes; int total;} tmes;


int main(){

   	FILE *arq;
   	FILE *escrever;
	char num[1000];
	
	tmes meses[13];
	
	for (int i=1; i<=12; i++) {
		meses[i].mes = i;
		meses[i].total = 0;
	}
		
	arq = fopen ("vendas.bin","rb");
	escrever = fopen ("totvendas.txt","wt");

	tvenda v; 

	while (fread(&v, sizeof(tvenda), 1, arq) != 0) 
		meses[v.mes].total += v.quantidade;

	fprintf(escrever,"Mes\tVendas\n");

	for (int i=1; i<=12; i++) {
		int j, maior = 1;
		
		for (int j=1; j<=12; j++) {			
			if(meses[j].total > meses[maior].total) {
				maior = j;
			}			
		}
		
		fprintf(escrever, "\t%d\t%d\n",meses[maior].mes, meses[maior].total);
		meses[maior].total = -1;
	}

	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO");
	}

	
	fclose(arq);
	fclose(escrever);
	return 0;
}
