#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
   	FILE *arq = fopen("Baskervilles.txt","rt");
   	FILE *arqsai = fopen("saida.txt","wt");
   	char linha[1000];
   	
//   	Ler linha a linha do arquivo fgets(string linha, limite string, pointer arquivo)
   	while(fgets(linha,1000,arq)!=NULL){

		for(int i = 0; linha[i] != '\0' && linha[i] != '\n'; i++){
		  linha[i] = tolower(linha[i]);
		  
		  if(linha[i] < 'a' || linha[i] > 'z') {
		  	linha[i] = ' ';
		  }
		}
		

		
		char *p = strtok(linha," ");
		while (p) {
			printf("%s\n",p);
			p=strtok(NULL," ");
		}
	// 	Escreve a linha no arquivo novo fprintf(pointer arquivo,tipo string, string)
		fprintf(arqsai,"%s",linha);	
	}
	
	fclose(arq);
	fclose(arqsai);
	return 0;
}
