
// 4) Faça um programa que permita calcular o custo de uma lista de compras. O programa possui como entrada um arquivo texto que na primeira linha possui um inteiro M que indica a quantidade de produtos que estão disponíveis para venda. Seguem os M produtos com seus preços respectivos por unidade ou Kg. A próxima linha de entrada contém um inteiro P que indica a quantidade de diferentes produtos que serão comprados, sendo que após P linhas contendo cada uma delas um texto (com até 50 caracteres) e um valor inteiro, que indicam respectivamente o nome de cada produto e a quantidade deste produto. Abaixo um exemplo de um arquivo de entrada.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[16];
    // char valor[1000];
    float valor;
} FRUTA;

void valorListaCompra(char nome_arquivo[10]){

    FILE *arquivoLeitura = fopen(nome_arquivo,"r"); 
    

    if(arquivoLeitura == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    int nfrutasVenda, nFrutasCompra;
    char linha[50]; //tamanho máximo da linha
    fgets(linha,50,arquivoLeitura);
    sscanf(linha, "%d", &nfrutasVenda);
    
    FRUTA *frutasVenda = malloc(nfrutasVenda * sizeof(FRUTA)); 

    for (int i = 0; i < nfrutasVenda; ++i) {

        // fgets(frutasVenda[i].nome, sizeof(frutasVenda[i].nome), arquivoLeitura);
        fgets(linha, sizeof(linha),arquivoLeitura); //ler linha

        /**
        char *fgets(char *str, int n, FILE *stream);

        str: É um ponteiro para a área de memória onde a string lida será armazenada.
        n: É o número máximo de caracteres a serem lidos, incluindo o caractere nulo de término de string ('\0').
        stream: É um ponteiro para o arquivo de onde os caracteres são lidos.
        */

        sscanf(linha, "%s %f", frutasVenda[i].nome, &frutasVenda[i].valor);
    }

    fgets(linha,50,arquivoLeitura);
    sscanf(linha, "%d", &nFrutasCompra);
    
    FRUTA *frutasCompra = malloc(nFrutasCompra * sizeof(FRUTA)); 

    for (int i = 0; i < nFrutasCompra; ++i) {

        fgets(linha, sizeof(linha), arquivoLeitura); //ler linha
        sscanf(linha, "%s %f", frutasCompra[i].nome, &frutasCompra[i].valor);
    }

    float valorTotal = 0;  
    for(int i = 0; i<nfrutasVenda; i++){
        for(int j = 0; j<nFrutasCompra; j++){
            if(strcmp(frutasVenda[i].nome, frutasCompra[j].nome) == 0){
                valorTotal += frutasVenda[i].valor * frutasCompra[j].valor;
            }
        }
    }

    printf("Valor total:  R$ %.2f\n", valorTotal);

    fclose(arquivoLeitura);
};


int main(){

    valorListaCompra("fruta.txt");

    return 0;
}