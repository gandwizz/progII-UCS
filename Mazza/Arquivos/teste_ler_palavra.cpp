#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(){
   	FILE *arq = fopen("saida.txt","rt");
   	char pal[1000];
   	int cnt = 0;
   	while (fscanf(arq, "%s", pal) != EOF) {
   		printf("%s\n",pal);
   		cnt++;
	}
   	
	
	fclose(arq);
	return 0;
}
