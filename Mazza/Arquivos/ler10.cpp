#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>


int main(){
	srand(time(NULL));
	int var_int;
		
	FILE *arq;
	
	arq = fopen("dados.bin","rb+");	

	int v,i;
	
   	for (i=0;i<10;i++) {
	   
	    fread(&v,sizeof(int),1,arq);
   		printf("v=%d\n",v);
   		
   		if ((v%2) == 0) {
   			fseek (arq, -sizeof(int), SEEK_CUR);
   			v = 0;
   			fwrite(&v,sizeof(int),1,arq);	
   			fflush(arq);
	    }

	}
	
	fseek (arq, 0, SEEK_SET);
	
	int w;
   	for (i=0;i<10;i++) {
    fread(&w,sizeof(int),1,arq);
		printf("%d\n",w);
	}

   	
	
	fclose(arq);
	return 0;
}
