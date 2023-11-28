// 1) Considere um arquivo texto que contém os nomes e as notas dos alunos de uma disciplina. As informações de cada aluno ocupam duas linhas do arquivo: a primeira linha contém o nome do aluno (com eventuais espaços em branco) e a segunda as três notas obtidas. Conside

// Fulano de Tal
// 6.3 5.7 7.1
// Sicrano Silva
// 3.4 5.4 4.7
// Beltrano Alves
// 9.2 6.8 8.3


// Escreva um programa que leia o arquivo “entrada.txt”, que contém as informações dos alunos no formato descrito acima, e imprima na tela o número de alunos aprovados e o número de alunos reprovados. Considere que um aluno é aprovado se obtiver média maior ou igual a cinco. Se não for possível abrir o arquivo, o programa deve ter como saída a mensagem “ERRO”. Para o exemplo ilustrado acima, a saída do programa seria:

// Aprovados: 2
// Reprovados: 1;

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    // escreve o arquivo

   	// FILE *arqEscreve;
    // arqEscreve = fopen ("“entrada.txt","wt");

    // fprintf(arqEscreve,"%s","Fulano de Tal\n");	
    // fprintf(arqEscreve,"%s","6.3 5.7 7.1\n");	
    // fprintf(arqEscreve,"%s","Sicrano Silva\n");	
    // fprintf(arqEscreve,"%s","3.4 5.4 4.7\n");	
    // fprintf(arqEscreve,"%s","Beltrano Alves\n");	
    // fprintf(arqEscreve,"%s","9.2 6.8 8.3\n");	



   	FILE *arq;
    char num[1000];
    char lnum[1000];  
	
    arq = fopen ("“entrada.txt","rt");


    if(arq == NULL){
        printf("ERRO");
    }

    char comp[]=" ";

    int nlinha = 1;
    float soma = 0;
    int apr = 0;
    int rep = 0;

    while(fgets(num,1000,arq)!=NULL){
        if (nlinha % 2 == 0) {
            
            char *p = strtok(num," ");
            while (p) {
                printf("%s\n",p);

                soma += atof(p);
                
                p=strtok(NULL," ");
            }

            printf("soma:%f \n", soma);

            if ((soma/3) < 5)
                rep++;
                    else    
                        apr++;
            soma = 0;

        }
		nlinha++;
    }

    printf("aprovados:%d\n",apr);
    printf("repovados:%d\n",rep);

	
	fclose(arq);
	return 0;
}
