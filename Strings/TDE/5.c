//5) Faça uma função que receba um valor inteiro e converta o valor para um string, retornando o string. Ex: se receber 45 deve retornar o string "45"
#include <stdio.h>

void intToString(int num, char* str, int base) {
    sprintf(str, "%d", num);
}

int main() {
    int numero = 12345;
    char buffer[20];

    intToString(numero, buffer, 10);

    printf("O número como string: %s\n", buffer);

    return 0;
}



//Utilizando a função "itoa" "int to array/string"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numero = 12345;
    char buffer[20]; // Um buffer para armazenar a string resultante

    // Uso da função itoa
    itoa(numero, buffer, 10);

    printf("O número como string: %s\n", buffer);

    return 0;
}

