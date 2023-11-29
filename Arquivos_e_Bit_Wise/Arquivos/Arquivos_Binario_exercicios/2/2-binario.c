
#include<stdio.h>
#include<stdlib.h>


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


void histograma(char arq[12]){

  FILE *arquivo = fopen(arq,"rb");
  FILE *arquivoSaida = fopen("histograma.txt","w");

  int num;
  int vetor[5] = {0};
  while(fread(&num,sizeof(float),1,arquivo) == 1){ 
    vetor[num-1]++;
  }


  for(int i = 0; i<5; i++){
    fprintf(arquivoSaida,"%d",i+1);

    for(int j = 0; j<vetor[i]; j++){
      fprintf(arquivoSaida,"*");
    }

    fprintf(arquivoSaida,"\n");
  }
  
  
  fclose(arquivo);
  fclose(arquivoSaida);
}



int main(){

  txtToBin("valores.txt","arquivobin.dat");
  histograma("arquivobin.dat");

  return 0;
}