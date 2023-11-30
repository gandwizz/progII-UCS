#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct{
    char nome[50];
    float nota1;
    float nota2;
    float nota3;
}ALUNO;

void lerDadosAlunos(char arq1[20], char arq2[20]){

    FILE * arq1 = fopen(arq1, "rb");
    FILE * arq2 = fopen(arq2, "wt");

    if(arq1 == NULL || arq2 == NULL)printf("Deu erro ao abrir arquivo");


    //Descobrir a quantidade de alunos
    fseek(arq1, 0, SEEK_END); //Joga o ponteiro para o final do arquivo
    long tamanho_arquivo = ftell(arq1); //pega o valor em bytes do arquivo
    rewind(arq1);//joga o ponteiro para o início do arquivo denovo

    size_t numeroAlunos = tamanho_arquivo/sizeof(ALUNO);


    //Vamos alocar um vetor de alunos

    ALUNO *alunos = malloc(numeroAlunos * sizeof(ALUNO));

    //Agora é necessário ler os dados do arquivo e passar para o vetor de alunos

    fread(alunos, sizeof(ALUNO), numeroAlunos, arq1); 

    //Calcular a média e já salvar os dados dos alunos no novo arquivo de texto
    for (int i = 0; i < numeroAlunos; i++){
        float media = 0;

        media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3 ;

        fprintf(arq2, "%s %f\n", alunos[i].nome, media );
    }
    
    fclose(arq1);
    fclose(arq2);

}

int main(){

    lerDadosAlunos("dados.bin", "alunos.txt");


    return 0;
}