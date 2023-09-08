// 2) Faça uma função que receba um string e retorne o comprimento da maior sequência de letras iguais em sequência no string.

#include <stdio.h>
#include <string.h>


int comprimento(char s[200]){

    int i, contador = 0, max = 0;
    char letra_anterior = [0];

    for(i=0; i < strlen(s); i++){
        char letra_atual = s[i];
        if(letra_atual == letra_anterior ){
            contador ++;  // Se a letra atual for igual à anterior, aumentamos o contador
        }else{
            if(contador > max){
                max = contador; // Se o contador atual for maior que o máximo, atualizamos o máximo
            }
            contador = 1; //Resete o contador para 1 para começar a contar a nova sequência
        }

        letra_anterior = letra_atual; 
    }

    if (contador > max) {
        max = contador; // Verificamos uma última vez no final da string
    }

    return max;
}


int main()
{
    char string[200]; 

    scanf("%s", string);

    int sequencia = comprimento(string);

    printf("%d", sequencia);

    return 0;
}
