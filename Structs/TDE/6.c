// 5) Fazer uma função escrita na linguagem de programação C que receba como parâmetro a lista de alunos de uma turma e retorne a quantidade de alunos aprovados. Para ser aprovado cada aluno precisa possuir média maior ou igual a 6 e a quantidade de faltas não pode ser maior que 15. Use as definições a seguir:


#include <stdio.h>
#include <string.h>

#define QTDALU 10   // quantidade de alunos
#define QTDNOT 3    // quantidade de notas por aluno

typedef struct st_aluno {
    char nome[41];
    float notas[QTDNOT];
    int faltas;
} Aluno;

int qtdAprovados(Aluno a[QTDALU]) {

    int n_aprovados = 0;
    for (int i = 0; i < QTDALU; i++) {

        int mediaNotas = 0;  // Inicialize fora do loop
        for (int j = 0; j < QTDNOT; j++) {
            mediaNotas += a[i].notas[j];
        }
        mediaNotas /= QTDNOT;  // Calcule a média aqui

        if (mediaNotas >= 6 && a[i].faltas <= 15) {
            n_aprovados++;
        }
    }

    return n_aprovados;
}

int main(void) {
    Aluno alunos[QTDALU] = {
        {"João", {7.5, 8.0, 9.5}, 2},
        {"Maria", {9.0, 8.5, 7.0}, 0},
        {"Pedro", {6.5, 7.0, 6.0}, 4},
        {"Ana", {8.0, 7.5, 8.0}, 1},
        {"Carlos", {7.0, 7.5, 6.5}, 3},
        {"Luisa", {9.5, 9.0, 9.0}, 0},
        {"Mário", {7.5, 8.0, 7.5}, 2},
        {"Sofia", {8.0, 7.5, 8.5}, 1},
        {"Ricardo", {6.0, 6.5, 7.0}, 3},
        {"Laura", {8.5, 9.0, 8.5}, 0}
    };

    int resultado = qtdAprovados(alunos);
    printf("%d alunos foram aprovados\n", resultado);  // Corrigido

    return 0;
}
