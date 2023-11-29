
#include<stdio.h>
#include<stdlib.h>
#include <stdio.h>

typedef struct {
    float x;
    float y;
} Data;

typedef struct {
    float x;
    float y;
} PONTO;

float dist(){
  
}

void createBinaryFile(char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }

    Data data[] = {
        {3.4, 4.2}, {4.2, -3.6}, {7.6, -2.6}, {5.4, 3.8}, {8.2, 1.7},
        {-1.4, 3.7}, {-4.8, -3.5}, {3.8, 1.1}, {-2.3, 3.4}, {2.0, 3.7}
    };

    fwrite(data, sizeof(Data), sizeof(data) / sizeof(Data), file);

    fclose(file);
}

PONTO mais_distante_ponto_medio (char nomearquivo[]){



}



int main(){

  createBinaryFile("data.bin");

  return 0;
}