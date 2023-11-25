#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
	int var_int;
	
	FILE *arq;
	
	arq = fopen("dados.dat","wb");
	for (int i=0; i<=100; i++) {
			fwrite(&i,sizeof(i),1,arq);
	}


   	
	
	fclose(arq);
	return 0;
}
