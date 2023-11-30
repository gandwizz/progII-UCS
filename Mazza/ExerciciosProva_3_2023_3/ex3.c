#include <stdio.h>
#include <string.h> 

int main(){
    FILE *arq = fopen("entrada.txt","rt");
    FILE *arq2 = fopen("saida.txt","wt");

    if (arq == NULL){
        printf("erro");
    }

    char pal[1000];
    int cnt = 0;
    while (fscanf(arq, "%s", pal) != EOF) {
        int cont = 0;
        for(int i=1; pal[i]!='\n' && pal[i]!='\0'; i++) {
            cont++;
        }

        int i,j;
        char contr[1000] = "";

        for (int i = 0, j=cont; i < cont, j>=0; i++, j--)
        {
            contr[i] = pal[j];
        }
        if(strcmp(pal,contr)==0) {
            fputs(pal ,arq2);
            fputs("\n" ,arq2);
        }
	}

    fclose(arq);
    fclose(arq2);
    return 0;
}