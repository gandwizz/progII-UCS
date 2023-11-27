// 3) Fa¸ca um programa que escreva os 100 primeiros n´umeros
// primos em um arquivo primos.dat.
#include <stdio.h>
#include <stdlib.h>


int ehPrimo(int num){

    if(num < 2) return 1;

    for(int i = 0; i*i <= num; i++ ){
        if(num % i == 0) return 0;
    }
    return 1;
}

void main(){
    FILE * arqPrimo;
    int cont = 0, num = 0;
    arqPrimo = fopen("primos.dat", "wt"); 


    while(cont < 100){
        
        if(ehPrimo(num)){
            fprintf(arqPrimo, "%d\n", num);
            cont++;
        }
        num++;
        
    }
    fclose(arqPrimo);

}