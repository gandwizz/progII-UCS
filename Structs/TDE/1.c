// 1) Faça uma função que receba uma string contendo uma data no formato DD/MM/AAAA. Separe o dia, o mês e o ano, retornando-os em uma struct. Use a definição de tipo e o protótipo da função a seguir:

// typedef struct data{int dia;int mes;int ano;} tdata;

// tdata convertedata(char stdata[ ]);

#include <stdio.h>


typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

Data separarData(char * string){
    Data resultado;

    sscanf(string, "%d/%d/%d", &resultado.dia, &resultado.mes, &resultado.ano);

    return resultado;
};

int main(void){
    char data[] = "05/11/2002";

    Data dataformatada = separarData(data);

    printf("Dia: %d\nMes: %d\nAno: %d\n", dataformatada.dia, dataformatada.mes, dataformatada.ano );

}
