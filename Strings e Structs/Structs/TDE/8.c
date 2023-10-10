// 8) Faça uma função que receba um string e converta todos os seus caracteres minúsculos para caracteres maiúsculos.  


#include <stdio.h>

void stringParaMinusculas(char *str) {
    int i = 0;
    while (str[i]) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            // Se o caractere estiver em maiúsculas, converta para minúsculas
            str[i] = str[i] + ('a' - 'A');
        }
        i++;
    }
}

int main() {
    char minhaString[] = "Converte ISSO para Minúsculas";

    printf("String original: %s\n", minhaString);

    stringParaMinusculas(minhaString);

    printf("String em minúsculas: %s\n", minhaString);

    return 0;
}


#include <stdio.h>
#include <ctype.h> // Para tolower()

void stringParaMinusculas(char *str) {
    int i = 0;
    while (str[i]) {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main() {
    char minhaString[] = "Converte ISSO para Minúsculas";

    printf("String original: %s\n", minhaString);

    stringParaMinusculas(minhaString);

    printf("String em minúsculas: %s\n", minhaString);

    return 0;
}

