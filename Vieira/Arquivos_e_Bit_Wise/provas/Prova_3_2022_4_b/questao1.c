// Faça um programa que leia um arquivo binário “vendas.bin”, e gere um arquivo texto “totvendas.txt” com um relatório de vendas por mês, ordenada em ordem decrescente de total de vendas. Exemplo de relatório:
// Mês         Vendas
//  7              1000000
//  5               900000
//  12               880000


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct venda{
    int dia;
    int mes;
    int ano;
    int quantidade;
} tvenda;


void relatorio(char nome_arquivo[20]){

    FILE * arq = fopen(nome_arquivo, "rb");
    FILE * arqSaida = fopen("totvendas.txt", "wt");


    //Pegar o número total
    fseek(arq,0,SEEK_END);
    long vendas_byte = ftell(arq);
    rewind(arq);

    int num_vendas = vendas_byte/sizeof(tvenda);
    tvenda * vendas = malloc(num_vendas * sizeof(tvenda));
    fread(vendas, sizeof(tvenda), num_vendas, arq);

    for (int i = 0; i < num_vendas; i++){
        for (int j = i+1; j < num_vendas; j++){

            if(vendas[i].quantidade < vendas[j].quantidade){
                tvenda aux = vendas[i];
                vendas[i] = vendas[j];
                vendas[j] = aux;
            }
        }
    }

    fprintf(arqSaida,"MÊS\tVENDA");
    for (int i = 0; i < num_vendas; i++){
        fprintf(arqSaida,"%d\t%d", vendas[i].mes, vendas[i].quantidade );
    }
    
    
    fclose(arq);
    fclose(arqSaida);

}


int main(){

    relatorio("vendas.bin");


    return 0;
}