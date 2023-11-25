#include <stdio.h>

int eh_primo(int num) {
	if(num < 2) return 1;
	
	for (int i=2; i*i<=num; i++) {
		if(num % i == 0) return 0;
	}
	
	return 1;
}


int main(){
   	FILE *arq;
	int num;
	int primo, cont = 0;
   	arq = fopen ("primos.txt","at");
   	
   	

	for (int i = 0; cont < 100; i++)
	{
		primo = eh_primo(i);
		if(primo) {
	   		fprintf(arq,"%d \n",teste);
	   		cont++;
		}
	}
	
	fclose(arq);
	return 0;
}
