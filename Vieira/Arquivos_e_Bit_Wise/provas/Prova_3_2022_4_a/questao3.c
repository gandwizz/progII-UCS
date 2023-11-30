/*
3.3 pontos) Considerando que um registro de data e horário é armazenado em uma variável inteira de 32 bits sem sinal,
onde os 6 bits menos significativos são o minuto, os 5 bits subsequentes são a hora, a seguir,  5 bits para o dia, depois 4
bits para o mês e finalmente os 12 bits mais significativos para o ano, conforme exemplo. Fazer uma função escrita na
linguagem de programação C que receba como parâmetro essa variável (uint32_t), utilize operadores bitwise:
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>



/**
 * DD/MM/AAAA HH:MM.
 * 011111100110 ano
 * 1100 mes
 * 00111  dia
 * 00101 hora
 * 101000 minuto

*/

void mostraDataHora(unsigned int c){

    //separar minuto
    unsigned int controle = 1;
    unsigned int mascaraMin = 0;
    unsigned int mascaraHora = 0;
    unsigned int mascaraDia = 0;
    unsigned int mascaraMes = 0;
    unsigned int mascaraAno = 0;


    //Minutos --> temos que pegar 6 bits
    for(int i = 0; i<6; i++){
        mascaraMin |= controle << i;
    }

    //Hora e Dia --> temos que pegar 5 bits
    for(int i = 0; i<5; i++){
        mascaraHora |= controle << i;
        mascaraDia |= controle << i;
    }

    //Mes --> temos que pegar 4 bits
    for(int i = 0; i<4; i++){
        mascaraMes |= controle << i;
    }
    //Ano --> temos que pegar 12 bits
    for(int i = 0; i<12; i++){
        mascaraAno |= controle << i;
    }

    //deslocar as máscaras para o local certo
    mascaraHora<<=6; 
    mascaraDia<<=11;
    mascaraMes<<=16;
    mascaraAno<<=20;

    unsigned int min = mascaraMin & c;
    unsigned int hora = (mascaraHora & c) >> 6;
    unsigned int dia = (mascaraDia & c) >>11;
    unsigned int mes = (mascaraMes & c) >>16;
    unsigned int ano = (mascaraAno & c) >>20;

    printf("%d/%d/%d %d:%d.", dia, mes, ano, hora, min);


}

int main() {
    unsigned int dataHora = 2121021800;

    mostraDataHora(dataHora);

    return 0;
}