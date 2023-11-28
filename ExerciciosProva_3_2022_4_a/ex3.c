// Considerando que um registro de data e horário é armazenado em uma variável inteira de 32 bits sem sinal,
// onde os 6 bits menos significativos são o minuto, os 5 bits subsequentes são a hora, a seguir,  5 bits para o dia, depois 4
// bits para o mês e finalmente os 12 bits mais significativos para o ano, conforme exemplo. Fazer uma função escrita na
// linguagem de programação C que receba como parâmetro essa variável (uint32_t), utilize operadores bitwise:
//  &   |   ~   ^   <<    >>   para separar as informações e escreva a data no formato: DD/MM/AAAA HH:MM.

#include <stdio.h>

void mostraDataHora(unsigned int dataHora){
    unsigned int insere = 1;
    unsigned int mascaraMin = 0;
    unsigned int mascaraHora = 0;
    unsigned int mascaraDia = 0;
    unsigned int mascaraMes = 0;
    unsigned int mascaraAno = 0;
    
    for(int i=0; i<6; i++){
        mascaraMin |= insere<<i;
    }

    for(int i=0; i<5; i++){
        mascaraHora |= insere<<i;
    }

    for(int i=0; i<5; i++){
        mascaraDia |= insere<<i;
    }   

    for(int i=0; i<4; i++){
        mascaraMes |= insere<<i;
    }   

    for(int i=0; i<12; i++){
        mascaraAno |= insere<<i;
    }

    unsigned int minuto = dataHora & mascaraMin;
    unsigned int hora = dataHora>>6 & mascaraHora;
    unsigned int dia = dataHora>>11 & mascaraDia;
    unsigned int mes = dataHora>>16 & mascaraMes;
    unsigned int ano = dataHora>>20 & mascaraAno;
    
    printf("%d/%d/%d %d:%d\n",ano,mes,dia,hora,minuto);



}

int main() {
    unsigned int dataHora = 2121021800;

    mostraDataHora(dataHora);

    return 0;
}