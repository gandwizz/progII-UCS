// 3) Faça uma função que receba um valor inteiro entre 0 e 99 e retorne (como parâmetro), um string com o valor por extenso. Ex: Se a função receber o valor 25, deve retornar o string "vinte e cinco".



//SEM UTILIZAR BIBLIOTECA

#include <stdio.h>
#include <string.h>

char *unidades(int n){

    char *nomes[] = {"zero", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
    return nomes[n];
}

char *dezenas(int n){

    char *nomes[] = {"", "", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};

    if(n < 10){
        return unidades(n); // caso for menor que 10, converte para unidades
    } else if( n % 10 == 0){ //verifica se o numero é múltiplo de 10
        return nomes[n / 10];
    }else{
        static char resultado[50]; // Declare um array de caracteres estático para armazenar o resultado
        snprintf(resultado, sizeof(resultado), "%s e %s", nomes[n / 10], unidades(n % 10));
        return resultado;
    }
}
char *centenas(int n){

    char *nomes[] = {"", "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

    if(n < 100){
        return dezenas(n); // caso for menor que 100, converte para dezenas
    } else if( n % 100 == 0){ //verifica se o nero é múltiplo de 100
        return nomes[n / 10];
    }else{
        static char resultado[50]; // Declare um array de caracteres estático para armazenar o resultado
        snprintf(resultado, sizeof(resultado), "%s e %s", nomes[n / 100], dezenas(n % 100));
        return resultado;
    }
}


int main()
{
    int numero; 
    scanf("%d", &numero);

    if(numero < 0  || numero > 99){
        printf("Numero fora do intervalo suportado");
    }else{
        printf("%s\n", centenas(numero));
    }
    return 0;
}



// Utilizando biblioteca *só tem q importar certo
#include <stdio.h>
#include <extenso.h>

int main() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero < 0 || numero > 999999999) {
        printf("Número fora do intervalo suportado.\n");
    } else {
        char *extenso = extenso_por_extenso(numero, EX_NUMERO);
        printf("O número %d por extenso é: %s\n", numero, extenso);
    }

    return 0;
}

