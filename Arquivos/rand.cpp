#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


int main(){
	srand(time(NULL));
	int var_int;
	
	
	FILE *arq;
	
	arq = fopen("rand.dat","wb");
	

	
	for (int i=0; i<=100; i++) {
		var_int = rand()%100;
		fwrite(&var_int,sizeof(var_int),1,arq);
		printf("%d \n",var_int);
	}


   	
	
	fclose(arq);
	return 0;
}
