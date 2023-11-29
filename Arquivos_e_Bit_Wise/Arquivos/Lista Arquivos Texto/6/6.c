#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    int ouro;
    int prata;
    int bronze;
}TIME;

void medalhas(char nome_arquivo[5]){

    FILE *arquivo = fopen(nome_arquivo,"r"); 
    FILE *arquivoSaida = fopen("timesEmOrdem","wt"); 
    
    if(arquivo == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(1);
    }

    int nTimes;
    char linha[1000];
    fgets(linha,50,arquivo);
    sscanf(linha, "%d", &nTimes);

    TIME *times = malloc(nTimes * sizeof(TIME));

    for(int i = 0; i < nTimes; i++){
        fgets(linha, sizeof(linha), arquivo); //pega a linha
        sscanf(linha, "%s %d %d %d\n", 
            times[i].nome, 
            &times[i].ouro,
            &times[i].prata,
            &times[i].bronze
        );
    }

    for(int i  = 0; i<nTimes; i++){
        for(int j = i+1; j<nTimes; j++){
        
        if( times[i].ouro < times[j].ouro || 
            times[i].ouro == times[j].ouro && times[i].prata < times[j].prata || 
            times[i].ouro == times[j].ouro && times[i].prata == times[j].prata  && times[i].bronze < times[j].bronze || 
            times[i].ouro == times[j].ouro && times[i].prata == times[j].prata  && times[i].bronze == times[j].bronze && (strcmp(times[i].nome, times[j].nome) > 0)
        ){
            TIME aux = times[i];
            times[i] = times[j];
            times[j] = aux;
        }

        }
    }


    for(int i  = 0; i<nTimes; i++){
        
        fprintf(arquivoSaida, "%s %d %d %d\n",times[i].nome, times[i].ouro,times[i].prata, times[i].bronze);
    }


    fclose(arquivo);
    fclose(arquivoSaida);
};


int main(){

    medalhas("medalhas.txt");

    return 0;
}