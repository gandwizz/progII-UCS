#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}DATA;

typedef struct{
    char nome[50];
    char autor[50];
    DATA data;
}LIVRO;


int verificardata( DATA livro1, DATA livro2 ){
    
    if(livro1.ano < livro2.ano ||
        livro1.ano == livro2.ano && livro1.mes < livro2.mes ||
        livro1.ano == livro2.ano && livro1.mes == livro2.mes && livro1.dia < livro2.dia
    ){
        return 1;
    }else{
        return -1;
    }

}

void lerDadosLivros(char arq1[20], char arq2[20]){

    FILE * arq1 = fopen(arq1, "rb");
    FILE * arq2 = fopen(arq2, "wt");

    if(arq1 == NULL || arq2 == NULL)printf("Deu erro ao abrir arquivo");


    //Descobrir a quantidade de livros
    fseek(arq1, 0, SEEK_END); //Joga o ponteiro para o final do arquivo
    long tamanho_arquivo = ftell(arq1); //pega o valor em bytes do arquivo
    rewind(arq1);//joga o ponteiro para o início do arquivo denovo

    size_t numeroLivros = tamanho_arquivo/sizeof(LIVRO);


    //Vamos alocar um vetor de livros

    LIVRO *livros = malloc(numeroLivros * sizeof(LIVRO));

    //Agora é necessário ler os dados do arquivo e passar para o vetor de livros

    fread(livros, sizeof(LIVRO), numeroLivros, arq1); 


    LIVRO antigo = livros[0];
    LIVRO novo = livros[1];

    //Verificar qual livro é o mais atual e o mais antigo
    for (int i = 0; i < numeroLivros; i++){
        for (int j = 0; j < numeroLivros; j++){
            
            if( verificardata(livros[i].data, livros[j].data) > 0 ){
                antigo = livros[i];
            }
            if( verificardata(livros[i].data, livros[j].data) < 0 ){
                novo = livros[i];
            }
        }
        
    }
    
    fprintf(arq2, "Livro Mais Antigo\nTítulo:%sAutor.:%s\nEdição:%d/%d/%d",antigo.nome, antigo.autor,antigo.data.dia, antigo.data.mes, antigo.data.ano );

    fprintf(arq2, "Livro Mais Novo\nTítulo:%sAutor.:%s\nEdição:%d/%d/%d",novo.nome, novo.autor,novo.data.dia, novo.data.mes, novo.data.ano );

    fclose(arq1);
    fclose(arq2);

}

int main(){

    lerDadosLivros("dados.bin", "livros.txt");
    return 0;
}