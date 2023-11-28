// 1) Considere um arquivo texto que contém os nomes e as notas dos alunos de uma disciplina. As informações de cada aluno ocupam duas linhas do arquivo: a primeira linha contém o nome do aluno (com eventuais espaços em branco) e a segunda as três notas obtidas.

// Escreva um programa que leia o arquivo “entrada.txt”, que contém as informações dos alunos no formato descrito acima, e imprima na tela o número de alunos aprovados e o número de alunos reprovados. Considere que um aluno é aprovado se obtiver média maior ou igual a cinco. Se não for possível abrir o arquivo, o programa deve ter como saída a mensagem “ERRO”. Para o exemplo ilustrado acima, a saída do programa seria:


// fgets(); --> retorna NULL no final do arquivo 
// fscanf() --> retorna numero de itens que foram atribuídos 
// fread() --> comando p/binário, retorna 0 no final do arquivo


#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[100];
    float notas[3];
}Aluno;



void calcularMedias(Aluno *alunos, int numAlunos, int *aprovados, int *reprovados) {
    *aprovados = 0;
    *reprovados = 0;

    for (int i = 0; i < numAlunos; i++) {
        float media = (alunos[i].notas[0] + alunos[i].notas[1] + alunos[i].notas[2]) / 3.0;

        // printf("media=%f\n", media);
        if (media >= 5.0) {
            (*aprovados)++;
        } else {
            (*reprovados)++;
        }
    }
}


int main(){

    FILE *arquivo = fopen("entrada.txt","r"); //abertura do arquivo para leitura

    int numAlunos = 0, aprovados, reprovados;
    Aluno alunos[3];

    if(arquivo == NULL){
        printf("ERRO");
        return 0;
    }

    while (fscanf(arquivo, "%[^\n]s", alunos[numAlunos].nome) == 1) {
        for (int i = 0; i < 3; i++) {
            if (fscanf(arquivo, "%f", &alunos[numAlunos].notas[i]) != 1) {
                fprintf(stderr, "ERRO\n");
                exit(EXIT_FAILURE);
            }
        }
        
        printf("%s", alunos[numAlunos].nome);
        numAlunos++;
    }


    fclose(arquivo);
    calcularMedias(alunos, numAlunos, &aprovados, &reprovados);


    printf("Aprovados: %d\n", aprovados);
    printf("Reprovados: %d\n", reprovados);

    return 0;
}