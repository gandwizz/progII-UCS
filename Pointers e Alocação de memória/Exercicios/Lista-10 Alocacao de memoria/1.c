// 1) Fazer uma função que gere e retorne uma string S com N caracteres C. O protótipo da função é dado por:
// char * gerastr(int n, char c)

#include <stdlib.h>
#include <stdio.h>
char * gerastr(int n, char c){
    char * s = (char *)malloc((n+1) * sizeof(char));

    for(int i = 0; i < n; i++){
        s[i] = c;
    }

    s[n] = '\0';

    return s; //tem que retornar o endereço
}

int main(void){
    printf("%s",gerastr(5,'g'));
}