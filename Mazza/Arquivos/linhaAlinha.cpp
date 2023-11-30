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


int main(){
   	FILE *arq;
	char num[1000];
	
   	arq = fopen ("Baskervilles.txt","rt");
   	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO");
   	}
   	
   	
   	while(fgets(num,1000,arq)!=NULL)
   	printf("%s",num);

	
	fclose(arq);
	return 0;
}
