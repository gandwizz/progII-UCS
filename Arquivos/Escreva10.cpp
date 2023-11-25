#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


int main(){
	srand(time(NULL));
	int var_int;
		
	FILE *arq;
	
	arq = fopen("dados.dat","wb");	

	
	for (int i=0; i<10; i++) {
		printf("Escreva o valor: \n");
		scanf("%d", &var_int);
		
		fwrite(&var_int,sizeof(var_int),1,arq);

	}


   	
	
	fclose(arq);
	return 0;
}
