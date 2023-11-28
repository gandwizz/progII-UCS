
#include<stdio.h>
#include<stdlib.h>

typedef struct estado{
  char nome[31];
  int numveic;
  int numacid;
}ESTADO;

void txtToBin(char txtFileName[50], char binFileName[50]) {
    FILE *txtFile = fopen(txtFileName, "r");
    FILE *binFile = fopen(binFileName, "wb");

    if (txtFile == NULL || binFile == NULL) {
        printf("Erro na abertura dos arquivos.\n");
        exit(1);
    }

    int numero;

    while (fscanf(txtFile, "%d", &numero) == 1) {
        fwrite(&numero, sizeof(int), 1, binFile);
    }

    fclose(txtFile);
    fclose(binFile);
}


ESTADO estado_maior_numero_acidentes(char nome_arquivo[80]) {

  FILE *arquivo = fopen(nome_arquivo,"rb");

  if(arquivo == NULL){
    printf("Erro na abertura do arquivo\n");
    exit(1);
  }

  ESTADO estado_maior_numero_acidentes;
  fread(&estado_maior_numero_acidentes, sizeof(ESTADO), 1, arquivo); //Lê o primeiro estado

  for(int i =0; i<26; i++){
    ESTADO estado_atual;
    fread(&estado_atual, sizeof(ESTADO), 1, arquivo);

    if(estado_atual.numacid > estado_maior_numero_acidentes.numacid){
      estado_maior_numero_acidentes = estado_atual;
    }

  }
  
  fclose(arquivo);
  return estado_maior_numero_acidentes;
}



int main(){

   const int numEstados = 26;
    ESTADO estados[numEstados];

    gerarDados(estados, numEstados);
    salvarDados(estados, numEstados, "dados_estados.dat");

  // maiorNumeroAcidentes("arquivobin.dat");

  return 0;
}