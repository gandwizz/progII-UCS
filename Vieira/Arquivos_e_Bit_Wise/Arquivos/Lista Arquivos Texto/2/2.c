// 2) Colocar 

// fgets(); --> retorna NULL no final do arquivo 
// fscanf() --> retorna numero de itens que foram atribuídos 
// fread() --> comando p/binário, retorna 0 no final do arquivo


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


float media (char mat[50], char nome_arquivo[50]){
    
    FILE *arquivo = fopen(nome_arquivo,"r"); //abertura do arquivo para leitura
    float n1,n2,n3;

    char linha[1000]; //tamanho máximo da linha

    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        if(strstr(linha, mat) != NULL){ //procura a matrícula na linha
            sscanf(linha, "%*s%f%f%f", &n1, &n2, &n3);
            float media = (n1 +n2+n3) / 3.0;
            fclose(arquivo);
            return media;

        }
    }
    return -1;
};


int main(){

    printf("%f\n",media("9010087-2", "alunos.txt"));

    return 0;
}