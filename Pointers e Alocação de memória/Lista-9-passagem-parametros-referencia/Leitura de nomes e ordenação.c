#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char nomes[5][10] = {"Lu", "Zorisc", "Gabriel", "Jose", "Ana" };


void ordena(char *(ln[10]) ){

    int i,j;
    for(j=0; j<4; j++){
        for(i=0; i<4; i++){

            if(strcmp(ln[i], ln[i+1]) > 0){
                
                char *aux=ln[i];
                ln[i] = ln[i+1];
                ln[i+1] = aux;
            }

        }
    }
}


int main(){

    char *ln[10];
    int i;
    
    for(i=0; i<5; i++){
        ln[i]=(char*)malloc(strlen(nomes[i])+1);
        strcpy(ln[i], nomes[i]);
    }

    ordena(ln);
    
    for(i = 0; i<5; i++){
        printf("%s\n", ln[i]);
    }

    return 0;
}