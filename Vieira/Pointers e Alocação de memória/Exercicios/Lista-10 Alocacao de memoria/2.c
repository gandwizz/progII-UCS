// 2) Fazer uma função que gere e retorne uma string com N caracteres aleatórios. Cada caracter pode seraleatoriamente escolhido entre qualquer letra maiúscula, minúscula ou dígito. O protótipo da função é dado por: char *aleatoria(int n)

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

char *aleatoria(int n){
    char *s = (char *)malloc((n+1) *sizeof(char) );

    for(int i = 0; i < n; i++){
        s[i] = rand() - '0'; 
    }

    s[n]= '\0';
    
    return s;

}

int main(void){
    printf("%s\n", aleatoria(5));
}
