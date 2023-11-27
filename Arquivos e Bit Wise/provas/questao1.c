#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct venda{
    int dia;
    int mes;
    int ano;
    int quantidade;
}tvenda;

int main(){

    int totvend[13]={0};
    FILE *arqvenda = fopen("vendas.bin", "rb");
    FILE *arqsai = fopen("totvendas.txt", "wt");
    fprintf(arqsai, "Mes\tVendas\n");
    tvenda v;

    while(fread(&v, sizeof(tvenda), 1,arqvenda ) != 0){
        totvend[v.mes-1]+= v.quantidade;
    }
    fclose(arqvenda);

    int i = 0;
    for(i; i<12; i++){
        int j,maior = 0;

        for(j = 0; j<12; j++){
            if(totvend[j]>totvend[maior]){
                maior = j;
            }

            fprintf(arqsai, "%d\t%d\n", maior+1, totvend[maior]);
            printf("%d %d\n", maior+1, totvend[maior]);

            totvend[maior]=-1;
        }
    }

    return 0;
}