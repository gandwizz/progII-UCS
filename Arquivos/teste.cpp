#include <stdio.h>

int main() {
   FILE *arq;

   arq = fopen ("numeros.txt","wt");
	for(int i=1; i<=1000; i++) {
	   fprintf(arq,"%d \n",i);
   }

	
	
	fclose(arq);
	return 0;
}
