// 4) (2.5 pontos)  Faça um programa que leia um arquivo de inteiros “dados.dat” e substitua no
// próprio arquivo todos os inteiros maiores do que 1000 pelo valor 1000, e os valores menores do
// que -1000 pelo valor -1000

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main() {

    FILE * arq = fopen("dados.dat", "rb+");

    if(arq == NULL){
        printf("Deu erro!");
    }

    int num;
    while( fread(&num, sizeof(int),1, arq) != 0){

        long position = ftell(arq);
        if(num >1000){
            num = 1000;

        }else if( num < -1000){
            num = -1000;
        }

        fseek(arq, position - sizeof(int), SEEK_SET);
        fwrite(&num, sizeof(int), 1, arq);
        fseek(arq, 0, SEEK_CUR);
    }


    fclose(arq);
    return 0;
}
