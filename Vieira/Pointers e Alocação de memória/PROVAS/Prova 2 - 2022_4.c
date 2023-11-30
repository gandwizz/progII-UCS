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
#include <stdlib.h>
#include <string.h>

struct st_aluno {
    int codigo;
    char nome[41];
    float notas[3];
    int faltas;
};
typedef struct st_aluno TIPOALUNO;

// Implementar a função nomes_dos_alunos
char *nomes_dos_alunos(TIPOALUNO *alunos, int qtd){
  
  // Ordenar a lista de alunos 
  for(int i = 0; i < qtd; i++){
    for(int j = i+1; j < qtd; j++){
      if( strcmp(alunos[i].nome, alunos[j].nome) > 0 ){
        TIPOALUNO aux = alunos[i];
        alunos[i] = alunos[j];
        alunos[j] = aux;
      }
    }
  }

  //alocar dinamicamente uma string
  char * nomes = (char*)malloc((41*qtd+1) * sizeof(char));
  
  nomes[0] = '\0';
  //concatenar em uma string os alunos
  for(int i = 0; i < qtd; i++){
    strcat(nomes, alunos[i].nome);
    if(i != (qtd - 1)){
      strcat(nomes,";");
    }
  }
  
  return nomes;

}

int main() {
    TIPOALUNO alunos[7]={
      {  11, "Ana"       , {7.5, 8.2, 6.3}, 3 },
      {  12, "Joao Pedro", {7.2, 8.1, 6.0}, 3 },
      {  21, "Marcia",     {5.5, 6.2, 8.3}, 3 },
      {  47, "Sandra",     {9.5, 8.5, 9.5}, 3 },
      {  91, "Eduardo",    {7.1, 7.2, 8.7}, 3 },
      {  92, "Paulo",      {6.0, 6.0, 6.0}, 3 },
      {  95, "Maria",      {8.9, 9.2, 7.7}, 3 }
    };
    char *nomes;
    nomes=nomes_dos_alunos(alunos,7);
    printf("%s\n",nomes);
    free(nomes);
    return 0;
}   
