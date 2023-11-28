// Faça um programa que leia 20 numeros do teclado e escreva os números pares no arquivo "pares.dat" e os ímpares no arquivo impares.dat, ambos na raiz do drive C
#include <stdio.h>
#include <stdlib.h>


void main(){
    FILE * arqPar, * arqImp;

    arqPar = fopen("pares.dat", "wt"); 
    arqImp = fopen("impares.dat", "wt"); 

    for (int i = 1; i <= 1000; i++)
    {
        if(i % 2 == 0)fprintf(arqPar, "%d\n", i);
        else fprintf(arqImp, "%d\n", i);
    }
    
    fclose(arqPar);
    fclose(arqImp);

}