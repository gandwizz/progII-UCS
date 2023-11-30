// 6) Fazer uma função que identifique os alunos aprovados, armazenando o código e a média dos mesmos em um vetor. Considerar média harmônica 6 para aprovação. Alocar espaço para armazenar os aprovados.
// struct aluno_notas {
//   int codigo;
//   float nota1,nota2,nota3;
// };
// typedef struct aluno_notas ALUNO_NOTAS;
// struct aluno_media {
//    int codigo;
//    float media;
// };
// typedef struct aluno_media ALUNO_MEDIA;

// protótipo:  void encontra_aprovados(ALUNO_NOTAS alunos[], int qtdalunos, ALUNO_MEDIA aprovados[], int *qtdaprovados)


#include<stdio.h>
#include<stdlib.h>


typedef struct aluno_notas {
  int codigo;
  float nota1,nota2,nota3;
}ALUNO_NOTAS;

typedef struct aluno_media {
   int codigo;
   float media;
}ALUNO_MEDIA;

void encontra_aprovados(ALUNO_NOTAS alunos[], int qtdalunos, ALUNO_MEDIA aprovados[], int *qtdaprovados){
  ALUNO_NOTAS *alunosAlocados = (ALUNO_NOTAS *)malloc(qtdalunos * sizeof(ALUNO_NOTAS));

  for(int i = 0; i < qtdalunos; i++){
    alunosAlocados[i].codigo = alunos[i].codigo;
    alunosAlocados[i].nota1 = alunos[i].nota1;
    alunosAlocados[i].nota2 = alunos[i].nota2;
    alunosAlocados[i].nota3 = alunos[i].nota3;
  }
  
  ALUNO_MEDIA *alunosAprovados = (ALUNO_MEDIA *)malloc(qtdalunos * sizeof(ALUNO_MEDIA));
  int countAlunosAprovados = 0;

  for(int i = 0; i < qtdalunos; i++){
    float mediaHarmonica = 0;
    mediaHarmonica = (10 / ( (1 /alunosAlocados[i].nota1) + (1 /alunosAlocados[i].nota2) + (1 /alunosAlocados[i].nota3)));

    if(mediaHarmonica >= 6){
      alunosAprovados[countAlunosAprovados].codigo = alunosAlocados[i].codigo;
      alunosAprovados[countAlunosAprovados].media = mediaHarmonica;
      countAlunosAprovados++;
    }
  }

  //daria pra dar um realloc aqui pra dar uma otimizada na memória

  *qtdaprovados = countAlunosAprovados;

}