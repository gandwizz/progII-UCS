#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct funcionario {
    int codigo;
    char nome[50];
    DATA nascimento;
    float valor_hora;
} FUNCIONARIO;


void atualizaSalario(char nomeArquivo[20], int codigo, float novoValor){

    FILE * arq = fopen(nomeArquivo, "rb+"); //Abertura do arquivo para leitura/escrita

    FUNCIONARIO funcionario;
    while (fread(&funcionario, sizeof(FUNCIONARIO), 1, arq) == 1){
        if(funcionario.codigo == codigo){
            // Atualizar o valor da hora
            funcionario.valor_hora = novoValor;

            // Mover o ponteiro de arquivo para a posição correta
            fseek(arq, -sizeof(FUNCIONARIO), SEEK_CUR);

            // Escrever o funcionário atualizado de volta no arquivo
            fwrite(&funcionario, sizeof(FUNCIONARIO), 1, arq);
        }
    }
    

}
