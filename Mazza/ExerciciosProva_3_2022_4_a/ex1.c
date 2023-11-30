#include <stdio.h>

// Fazer uma função escrita na linguagem de programação C que mostre todos os nomes dos alunos
// armazenados no arquivo ‘alunos.dat’ em ordem contrária, ou seja, do último aluno gravado até o primeiro. Abaixo
// exemplo de um programa que armazena alguns alunos nesse arquivo e algumas funções que podem ser usadas. O
// programa deve funcionar para qualquer quantidade de registros e não para apenas os desse exemplo.
// fseek(arq, 0, SEEK_SET) // posiciona na posição 0 (deslocamento em bytes) a partir do início do arquivo (SEEK_SET).
// Outras opções SEEK_END (fim do arquivo), SEEK_CUR (posição corrente).
// ftell(arq) // Retorna a posição corrente no arquivo(em bytes) a partir da posição 0 (primeira posição do arquivo)
// fread(&variavel, sizeof(variavel), 1, arq) lê para a variável a partir da posição corrente do arquivo. Retorna quantos
// foram lidos, nesse caso 0 se não foi lido, ou 1 se foi lido.

#include <stdio.h>
#include <stdlib.h>
typedef struct st_aluno {
    int codaluno;
    char nomealuno[41];
    float notas[3];
    int faltas;
} TIPOALUNO;


int main(){

   	FILE *arq;
	arq = fopen ("alunos.dat","rb");
    
	if(arq == NULL){
		printf("ERRO NA ABERTURA DO ARQUIVO");
	}

    TIPOALUNO a;
    

    fseek(arq, sizeof(TIPOALUNO), SEEK_END);
    long int num = ftell(arq);
    int qtd = num/sizeof(TIPOALUNO) - 1;

    for (int i = 1; i <= qtd; i++)
    {
        fseek(arq, -i * sizeof(TIPOALUNO), SEEK_END);
        fread(&a, sizeof(TIPOALUNO), 1, arq);
        printf("%s\n",a.nomealuno); 
    }
	
	fclose(arq);
	return 0;
}
