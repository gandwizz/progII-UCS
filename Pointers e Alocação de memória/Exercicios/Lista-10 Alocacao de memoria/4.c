// 4) Faça uma função que receba por parâmetro um valor inteiro n e retorne um vetor de n inteiros alocado dinamicamente com os n primeiros primeiros números primos. Faça a função, inicializando as duas primeiras posições com 2 e 3, a verificação da primalidade dos números posteriores seja feita dividindo cada número apenas pelos primos menores que ele, que já estarão no vetor. Se o número não tiver divisores, ocupará a próxima posição livre do vetor. O protótipo da função é dado por:

//protótipo : int * primos( int n )

#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int is_prime(int num){
    if(num < 2){
        return 0;
    }

    for(int i = 2; i*i <= num; i++){ // i*i <= num é mais eficiente que i <= sqrt(num)
        if(num % i == 0) return 0;
    }

    return 1; // é primo
}

int * primos( int n ){
    int *vetor = (int*)malloc(n *sizeof(int));

    vetor[0] = 2; // primeiro termo
    vetor[1] = 3; // segundo termo

    int contador = 2; // contador de primos no vetor
    int numero = 4;

    while( n > contador ){
        if(is_prime(numero)){
            vetor[contador] = numero;
            contador++;
        }
        numero++;
    }

    return vetor;
}

int main() {
    int n = 10;  // Exemplo: obter os primeiros 10 números primos
    int *primes = primos(n);

    printf("Os primeiros %d números primos são:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", primes[i]);
    }

    // Libera a memória alocada
    free(primes);

    return 0;
}
