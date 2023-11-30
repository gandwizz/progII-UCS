/*
2) (3.4 pontos) Fazer um programa completo escrito na linguagem de programação C que leia um arquivo do tipo texto
chamado ‘texto01.txt’ e gravando todas as informações (exceto as linhas em branco) desse em outro arquivo também do
tipo texto chamado ‘texto02.txt’. Para facilitar, considere o tamanho máximo de cada linha 1000 caracteres. Assim pode-se
ler linha a linha com fgets(linha, sizeof(linha), arquivo). Lembrar que o ‘\n’ também é lido. Veja que essa função retorna
NULL quando atingir fim do arquivo, senão retorna um ponteiro para a linha. Para gravar, pode-se utilizar o fprintf a
função fputs(linha, arquivograva). Outra opção de implementação é ler caractere a caractere com getc(arquivo). Essa
função retorna o caracter lido, ou -1 caso seja encontrado fim de arquivo. Aqui pode-se escrever com putc(caractere,
arquivo), mas lembrar que precisa controlar linhas em branco e essas não são escritas no arquivo de saída.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){

    FILE *arq1 = fopen("texto01.txt", "rt");
    FILE *arq2 = fopen("texto02.txt", "wt");

    //ler um arquivo de texto, e salvar em outro

    char linha[1000];

    while(fgets(linha, sizeof(linha), arq1)){

        if( stcmp(linha, "\n") != 0 &&  stcmp(linha, "\r\n") != 0 ){
            fprintf(arq2, "%s", linha);
        }
    }

    return 0; 
}