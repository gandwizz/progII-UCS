/*
1) (3.3 pontos) Fazer uma função escrita na linguagem de programação C que escreva todos os nomes dos alunos
armazenados no arquivo ‘alunos.dat’ em ordem contrária, ou seja, do último aluno gravado até o primeiro. Abaixo
exemplo de um programa que armazena alguns alunos nesse arquivo e algumas funções que podem ser usadas. Considere
que o tamanho do arquivo é tal que não é possível carregá-lo todo para um vetor.
fseek(arq, 0, SEEK_SET) // posiciona na posição 0 (deslocamento em bytes) a partir do início do arquivo (SEEK_SET).
Outras opções SEEK_END (fim do arquivo), SEEK_CUR (posição corrente).
ftell(arq) // Retorna a posição corrente no arquivo(em bytes) a partir da posição 0 (primeira posição do arquivo) 
fread(&variavel, sizeof(variavel), 1, arq) lê para a variável a partir da posição corrente do arquivo. Retorna quantos 
foram lidos, nesse caso 0 se não foi lido, ou 1 se foi lido.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct st_aluno {
    int codaluno;
    char nomealuno[41];
    float notas[3];
    int faltas;
} ALUNO;

void mostraAlunosContrario( char nome_arquivo[20]){

    FILE * arq = fopen(nome_arquivo, "rb");

    fseek(arq, 0, SEEK_END);
    long alunos_byte = ftell(arq);
    
    int numAlunos = alunos_byte/sizeof(ALUNO);
    ALUNO aluno;

    for (int i = 0; i < numAlunos; i++) {
        fseek(arq, -i * sizeof(ALUNO), SEEK_END);
        fread(&aluno, sizeof(ALUNO), 1, arq);
        printf("%s\n", aluno.nomealuno);
    }

    
    fclose(arq);
}