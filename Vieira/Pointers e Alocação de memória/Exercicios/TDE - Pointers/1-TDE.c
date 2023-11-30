// 1) Fazer uma função que calcule a partir de um horário inicial (hora e minuto) mais uma quantidade de minutos, o horário correspondente ao horário inicial adicionado a essa quantidade de minutos.
// Protótipo:  void calc_horario(int h1, int m1, int qtdmin, int *h2, int *m2)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void calc_horario(int h1, int m1, int qtdmin, int *h2, int *m2){

    m1 += qtdmin;
    if(m1 > 60){
        h1 = m1/60;
        m1 %= 60;
    }

    h1 %= 24; 

    //trocar os valores dos ponteiros 
    *h2 = m1;  
    *m2 = h1;
}