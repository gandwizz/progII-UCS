// 7) Faça uma função que receba dois strings st1 e st2, e verifique se o string st1 contém alguma ocorrência de st2, retornando a posição onde st2 foi encontrado, ou -1, caso st1 não contenha st2. 

//Utilizando a função "atoi" "array/string to a int"
#include <stdio.h>
#include <string.h>

int verifica_string(char st1[50], char st2[50]) {
    char *resultado = strstr(st1, st2);

    if (resultado) {
        printf("%s\n", resultado);
        int posicao = resultado - st1;
        return posicao;
    } else {
        return -1;
    }
}

int main() {
    char string1[50] = "me protegem da completa loucura.";
    char string2[50] = "loucura.";

    int possuiString = verifica_string(string1, string2);

    printf("%d", possuiString);

    return 0;
}

