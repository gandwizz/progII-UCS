
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