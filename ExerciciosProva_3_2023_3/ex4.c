#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *arq = fopen("dados.dat","rb+");

    if (arq == NULL) {
        printf("erro");
    }

    int a;
    int b = 1000;

    while(fread(&a, sizeof(a),1,arq)!=0){
        printf("%d",a);

        if(a>1000) {
            fseek(arq,-1 * sizeof(a),SEEK_CUR);
            fwrite(&b,sizeof(b),1,arq);
        }
        printf("\n");
    }
        printf("\n ------------------------------------- \n");
        fseek(arq,0,SEEK_SET);

    while(fread(&a, sizeof(a),1,arq)!=0){
        printf("%d",a);
        printf("\n");
    }

    return 0;
}