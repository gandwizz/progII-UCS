// Faça um programa que crie um arquivo numeros.dat na raiz do drive C("C:\\"), com os números de 1 a 1000.

#include <stdio.h>
#include <stdlib.h>


void main(){
    FILE * arq;

    arq = fopen("numeros.dat", "wt"); 

    for (int i = 1; i <= 1000; i++)
    {
        fprintf(arq, "%d\n", i);
    }
    
    fclose(arq);

}