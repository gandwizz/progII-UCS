#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
   	FILE *arq;
   	int cont = 0;


	char num[1000];
	char lnum[1000];  
	
	char comp[]="holmes";
	
   	arq = fopen ("Baskervilles.txt","rt");
   	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO");
   	}
   	
   	
   	while(fgets(num,1000,arq)!=NULL){
   			
					
   			
   			for(int i = 0; num[i]; i++){
			  num[i] = tolower(num[i]);
			}
//   			printf("%s",num);
   			char *p = num;
   			
	   		while((p=strstr(p, comp))!=NULL){

	   				printf("%s",num);
					cont++;
					p++;

		   	}
	   	
		    
	}
   	printf("A palavra Holmes aparece: %d Vezes \n",cont);

	
	fclose(arq);
	return 0;
}
