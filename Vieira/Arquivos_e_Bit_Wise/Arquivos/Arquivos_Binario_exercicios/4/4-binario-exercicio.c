
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    float x;
    float y;
} Data;

typedef struct {
    float x;
    float y;
} PONTO;

float dist(PONTO p1, PONTO p2){

    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

void createBinaryFile(char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", filename);
        return;
    }

    Data data[] = { {3.4, 4.2}, {4.2, -3.6}, {7.6, -2.6}, {5.4, 3.8}, {8.2, 1.7},
        {-1.4, 3.7}, {-4.8, -3.5}, {3.8, 1.1}, {-2.3, 3.4}, {2.0, 3.7}
    };

    fwrite(data, sizeof(Data), sizeof(data) / sizeof(Data), file);

    fclose(file);
}

PONTO mais_distante_ponto_medio (char nomearquivo[50]){

    FILE *arquivo = fopen(nomearquivo, "rb");
    if (arquivo == NULL) {
        printf("Não foi possível abrir o arquivo %s\n", nomearquivo);
        return;
    }

    fseek(arquivo, 0, SEEK_END);  // Movendo para o final do arquivo
    long tamanho_arquivo = ftell(arquivo);  // Obtendo o tamanho do arquivo
    rewind(arquivo);  // Voltando ao início do arquivo

    int num_pontos = tamanho_arquivo / sizeof(PONTO);

    PONTO *pontos = malloc(num_pontos * sizeof(PONTO));
    
    fread(pontos, sizeof(PONTO), num_pontos, arquivo);

    PONTO maior = pontos[0];
    for (int i = 0; i < num_pontos; i++){
        for (int j = 0; i < num_pontos; i++){
            if(dist(pontos[i], pontos[j]) > dist( maior, pontos[j]) > 0){
                maior = pontos[i];
            };
        }
    }

    return maior;
}


int main() {
    createBinaryFile("data.bin");

    PONTO ponto_mais_distante = mais_distante_ponto_medio("data.bin");

    printf("Coordenadas do ponto mais distante em relação ao ponto médio:\n");
    printf("x: %.2f\n", ponto_mais_distante.x);
    printf("y: %.2f\n", ponto_mais_distante.y);

    return 0;
}