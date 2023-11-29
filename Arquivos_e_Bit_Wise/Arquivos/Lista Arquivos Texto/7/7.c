// Faça um programa em C que leia um arquivo texto chamado pedidos.txt, onde cada linha possui o número de uma peça, número de pedidos, e as quantidades requisitadas para os pedidos (o número de quantidades é definido pelo número de pedidos). O sistema deve produzir um segundo arquivo texto chamado media.txt que contenha o código da peça, o número de pedidos e a média de quantidades requisitadas em cada pedido. Para um arquivo de entrada com o seguinte conteúdo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo_peca;
    int num_pedidos;
    float *quantidades;
}PECA;

void pedidos(char nome_arquivo[5]){


    FILE *arquivo = fopen(nome_arquivo,"r"); 
    FILE *arquivoSaida = fopen("media.txt","wt"); 
    
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }
    int codigo_peca, num_pedidos;
    while(fscanf(arquivo, "%d %d", &codigo_peca, &num_pedidos ) == 2){ // fscanf retorna o número de valores atribuidos

        float *quantidades = malloc(num_pedidos * sizeof(float));

        //Lê as quantidades
        for(int i = 0; i < num_pedidos; i++){
            fscanf(arquivo, "%f", &quantidades[i]);
        }

        //Calcula a média
        float media = 0;
        for(int i = 0; i < num_pedidos; i++){
            media += quantidades[i];
        }

        media = media / num_pedidos; //Calcula a média

        fprintf(arquivoSaida, "%d %d %.2f\n", codigo_peca, num_pedidos, media);
    }


    fclose(arquivo);
    fclose(arquivoSaida);
};


int main(){

    pedidos("pedidos.txt");

    return 0;
}