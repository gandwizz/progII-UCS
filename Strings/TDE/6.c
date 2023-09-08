// 6) Faça uma função que receba um string com uma sequência de caracteres representando um número (ex: "123") e retorne, como valor de retorno da função, o valor numérico equivalente.


//Utilizando a função "atoi" "array/string to a int"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero = "12345";

    // Uso da função atoi
    atoi(numero);

    printf("string como numero: %s\n", numero);

    return 0;
}
//Ou podemos montar uma função pra ficar mais bonitinho...
