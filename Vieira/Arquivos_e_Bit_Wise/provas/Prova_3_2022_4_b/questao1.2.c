#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct venda {
    int dia;
    int mes;
    int ano;
    int quantidade;
} tvenda;

int main() {
    int totvend[12] = {0};  // Inicialize com zero para cada mês
    FILE *arqvenda = fopen("vendas.bin", "rb");
    FILE *arqsai = fopen("totvendas.txt", "wt");

    if (arqvenda == NULL || arqsai == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;  // Saída com erro
    }

    fprintf(arqsai, "Mes\tVendas\n");
    tvenda v;

    while (fread(&v, sizeof(tvenda), 1, arqvenda) != 0) {
        totvend[v.mes - 1] += v.quantidade;
    }

    fclose(arqvenda);

    for (int i = 0; i < 12; i++) {
        int maior = 0;

        // Encontrar o mês com maior quantidade de vendas
        for (int j = 1; j < 12; j++) {
            if (totvend[j] > totvend[maior]) {
                maior = j;
            }
        }

        if (totvend[maior] != -1) {
            fprintf(arqsai, "%d\t%d\n", maior + 1, totvend[maior]);
            printf("%d %d\n", maior + 1, totvend[maior]);

            totvend[maior] = -1;  // Marcar o mês como processado
        }
    }

    fclose(arqsai);

    return 0;
}
