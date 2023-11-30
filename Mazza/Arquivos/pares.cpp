#include <stdio.h>

int main(){
   	FILE *arq;
	int num;

   	arq = fopen ("pares.txt","wt");

	for (int i = 0; i < 20; i++)
	{
		printf("escreva o número: \n");
		scanf("%d",&num);
		if(num % 2 == 0) {
	   		fprintf(arq,"%d \n",num);
		}
	}
	
	fclose(arq);
	return 0;
}
