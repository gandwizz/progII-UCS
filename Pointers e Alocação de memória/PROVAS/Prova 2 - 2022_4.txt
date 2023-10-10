/*
1) (3.3 pontos) Fazer um programa completo escrito na linguagem de programação C que leia uma string e escreva quantas letras maiúsculas, quantas letras minúsculas e quantos dígitos existem na mesma. 
Crie obrigatoriamente uma função que receba como parâmetro uma string e retorne nos três parâmetros seguintes as quantidades de letras maiúsculas, minúsculas e dígitos dessa string. 
A função deve apenas retornar os valores nos parâmetros e os mesmos devem ser escritos após a chamada da função. Nada deve ser escrito dentro da função.
*/

#include <stdio.h>
#include <string.h>


void conta_caracter(char *str, int *nLmaiusculas, int *nLminusculas, int *digitos){

  *nLmaiusculas = 0;
  *nLminusculas = 0;
  *digitos = 0;

  for(char *ptr = str; *ptr != '\0'; ptr++){ // esse é o melhor jeito de percorrer strings!! até que tenha \0
    if( *ptr >= '0' && *ptr <= '9' ){
      (*digitos)++;
    }else if(*ptr >= 'A' && *ptr <= 'Z' ){
      (*nLmaiusculas)++;
    }else if(*ptr >= 'a' && *ptr <= 'z'){
      (*nLminusculas)++;
    }
  }
}

int main(void){

  char string[100];
  fgets(string, sizeof(string), stdin);

  int nLmaiusculas, nLminusculas, digitos;
  conta_caracter(string, &nLmaiusculas, &nLminusculas, &digitos);

  printf("N° digitos: %d\n", digitos);
  printf("N° letras maiusculas: %d\n", nLmaiusculas);
  printf("N° letras minusculas: %d\n", nLminusculas);
}







/*
2) (3.3 pontos) Fazer uma função escrita na linguagem de programação C que aumente o salário de um funcionário em X% caso tenha sido admitido antes de 25/10/2020. Exemplo de utilização no programa abaixo:
#include <stdio.h>
struct st_data { int dia,mes,ano; };
typedef struct st_data TIPODATA;
struct st_funcionario {
    int codigo;
    char nome[41];
    TIPODATA admissao;
    float salario;
};
typedef struct st_funcionario TIPOFUNC;

Implementar aumenta_salario
*/

#include <stdio.h>
#include <string.h>

struct st_data { int dia,mes,ano; };
typedef struct st_data TIPODATA;

struct st_funcionario {
    int codigo;
    char nome[41];
    TIPODATA admissao;
    float salario;
};
typedef struct st_funcionario TIPOFUNC;

void aumenta_salario ( TIPOFUNC * func, int porcentual_aumento){
  
  int mereceAumento = 0;
  if( func->admissao.ano < 2020 ||
      func->admissao.ano == 2020 && func->admissao.mes < 10 ||
      func->admissao.ano == 2020 && func->admissao.mes == 10 && func->admissao.dia < 25
    ){
    mereceAumento = 1;
  }

  if(mereceAumento){
    func->salario += func->salario * (porcentual_aumento/ 100.0);
  }
}



/*
3) (3.4 pontos) Fazer uma função escrita na linguagem de programação C que aloque dinamicamente e armazene em uma string os nomes dos alunos em ordem alfabética separados por ponto e vírgula. 
A ordenação dos nomes pode ser feita na própria lista de structs recebida. Abaixo exemplo de um programa que utiliza essa função. Para esse exemplo deveria escrever “Ana;Eduardo;Joao;Pedro;Marcia;Maria;Paulo;Sandra”
*/

#include <stdio.h>
#include <string.h>

typedef struct{
  char nome[50];
} ALUNO;

void ordena_nomes( ALUNO *alunos, int nAlunos ){
  ALUNO *nomes = (ALUNO*)malloc(nAlunos * sizeof(ALUNO)); 
  
  //separar os nomes 
  char p = strtok(alunos, ';');
  int posicaoNomes = 0;
  while( p != '\0' ){
    nomes[posicaoNomes].nome = p;
    p = strtok(alunos, NULL);
    posicaoNomes++;
  }

  for(int i = 0; i < nAlunos; i++){
    for(int j = i+1; i < nAlunos; j++){
      if( strcmp(nomes[i].nome, nomes[j].nome) > 0){
        char nomeAux[50];

        strcpy(nomeAux, nomes[i].nome);
        strcpy(nomes[i].nome, nomes[j].nome);
        strcpy(nomes[j].nome, nomeAux);
      }
    }
  }

}
