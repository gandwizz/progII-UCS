#include<stdio.h>
int main(){
    
    // FILE *arq1 = fopen("arq1", "wb");
    // FILE *arq2 = fopen("arq2", "wb");
    // int a;
    // a=1;
    // fwrite(&a, sizeof(int), 1, arq1);
    // a=3;
    // fwrite(&a, sizeof(int), 1, arq1);
    // a=6;
    // fwrite(&a, sizeof(int), 1, arq1);
    // a=8;
    // fwrite(&a, sizeof(int), 1, arq1);
    // a=1;
    // fwrite(&a, sizeof(int), 1, arq2);
    // a=2;
    // fwrite(&a, sizeof(int), 1, arq2);
    // a=4;
    // fwrite(&a, sizeof(int), 1, arq2);
    // a=8;
    // fwrite(&a, sizeof(int), 1, arq2);
    FILE *arq1 = fopen("arq1", "rb");
    FILE *arq2 = fopen("arq2", "rb");
    unsigned int conjunto1=0;
    unsigned int conjunto2=0;
    int n;
    while(fread(&n, sizeof(int), 1, arq1)){
        conjunto1|=(1<<n);
    }
    while(fread(&n, sizeof(int), 1, arq2)){
        conjunto2|=(1<<n);
    }
    FILE *arqr = fopen("diferenca.txt", "wt");
    int i;
    for(i=8; i>0; i--){
	    n=(conjunto1&~conjunto2)>>i&1;
	    if(n>0)
	        fprintf(arqr, "%d\n", i);
    }
    fclose(arq1);
    fclose(arq2);
    fclose(arqr);
}
