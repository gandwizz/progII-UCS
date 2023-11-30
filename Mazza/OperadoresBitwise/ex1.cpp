#include <stdio.h>
#include <stdlib.h>

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
   	unsigned int c;
   	
   	mostrabin(c);
   	int valor;
	
	printf("\n valor: \n");
	scanf("%d",&valor);
	
	insere(&c, valor);
	
	mostrabin(c);

	return 0;
}
