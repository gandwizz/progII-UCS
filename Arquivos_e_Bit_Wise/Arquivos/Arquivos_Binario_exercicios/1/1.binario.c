
#include<stdio.h>
#include<stdlib.h>


void txtToBin(char txtFileName[50], char binFileName[50]) {
    FILE *txtFile = fopen(txtFileName, "r");
    FILE *binFile = fopen(binFileName, "wb");

    if (txtFile == NULL || binFile == NULL) {
        printf("Erro na abertura dos arquivos.\n");
        exit(1);
    }

    float numero;

    while (fscanf(txtFile, "%f", &numero) == 1) {
        fwrite(&numero, sizeof(float), 1, binFile);
    }

    fclose(txtFile);
    fclose(binFile);
}


void mediaBinario(char arq[12]){

  FILE *arquivo = fopen(arq,"rb");

  float somatotal=0;
  float num, cont = 0;

  while(fread(&num,sizeof(float),1,arquivo) == 1){ //retorna 0 quando chega no fim do arquivo
    printf("%.2f\n",num);
    somatotal += num;
    cont ++;
  }
  
  printf("Media: %.2f\n",somatotal/cont);
  fclose(arquivo);
}



int main(){

  txtToBin("valores.txt","arquivobin.dat");
  mediaBinario("arquivobin.dat");

  return 0;
}