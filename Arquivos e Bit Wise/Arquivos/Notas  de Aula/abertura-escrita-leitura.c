
#include <stdlib.h>
#include <stdio.h>

void main(){

    FILE * arquivo;

    // arquivo = fopen('Nome do arquivo', "Modo de abertura ");

    arquivo = fopen('texto.txt',"wt"); //escrita de texto
    arquivo = fopen('texto.txt',"rt"); //leitura de texto

    fprint(arquivo, "aaaaa"); //Escrever alguma coisa no arquivo

    fclose(arquivo);
}

/*
fgets(); --> retorna NULL no final do arquivo 
fscanf() --> retorna EOF 
fread() --> comando p/binário, retorna 0 no final do arquivo


*/


/**LEITURA*/
void main(){

    FILE * arquivo;
    int i;
    arquivo = fopen("teste.txt", "rt");

    if(arquivo == NULL){printf("Erro na abertura!\n");}
    int valor;

    while(fscanf(arquivo, "%d", &valor) != EOF)
    for ( i = 0; i < 20; i++){
        
    }
    

    fclose(arquivo);
}
