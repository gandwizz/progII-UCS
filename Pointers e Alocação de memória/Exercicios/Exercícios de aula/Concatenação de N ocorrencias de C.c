//Faça uma função que receba um caracter C e um inteiro N, e retorne uma string alocado dinamicamente com a concatenação de N ocorrencias de C

#include <stdlib.h>
#include <stdio.h>
char * gerastr(int n, char c){
    char * s = (char *)malloc((n+1) * sizeof(char));

    for(int i = 0; i < n; i++){
        s[i] = c;
    }

    s[n] = '\0';

    return s; 
}

int main(void){
    printf("%s",gerastr(5,'g'));
}