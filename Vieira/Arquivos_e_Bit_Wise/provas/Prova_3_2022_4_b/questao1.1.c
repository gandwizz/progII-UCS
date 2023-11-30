#include <stdio.h>
#include <stdlib.h>

typedef struct venda {
    int dia;
    int mes;
    int ano;
    int quantidade;
} tvenda;

void gerarRelatorio(char nome_arquivo_binario[20], char nome_arquivo_texto[20]) {
    FILE *arquivo_binario = fopen(nome_arquivo_binario, "rb");
    FILE *arquivo_texto = fopen(nome_arquivo_texto, "wt");

    // Verificar se os arquivos foram abertos com sucesso
    if (arquivo_binario == NULL || arquivo_texto == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        exit(EXIT_FAILURE);
    }

    // Pegar o número total de vendas
    fseek(arquivo_binario, 0, SEEK_END);
    long vendas_byte = ftell(arquivo_binario);
    rewind(arquivo_binario);

    int num_vendas = vendas_byte / sizeof(tvenda);
    tvenda *vendas = malloc(num_vendas * sizeof(tvenda));
    fread(vendas, sizeof(tvenda), num_vendas, arquivo_binario);

    // Calcular o total de vendas por mês
    int total_vendas_por_mes[12] = {0}; // Inicializar o array com zeros

    for (int i = 0; i < num_vendas; i++) {
        int mes = vendas[i].mes;
        total_vendas_por_mes[mes - 1] += vendas[i].quantidade; // O mês começa de 1, não de 0
    }

    // Ordenar o array de total de vendas por mês em ordem decrescente
    for (int i = 0; i < 12; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (total_vendas_por_mes[i] < total_vendas_por_mes[j]) {
                // Trocar os valores
                int temp = total_vendas_por_mes[i];
                total_vendas_por_mes[i] = total_vendas_por_mes[j];
                total_vendas_por_mes[j] = temp;
            }
        }
    }

    // Escrever o relatório no arquivo de texto
    fprintf(arquivo_texto, "Mês\tVendas\n");
    for (int i = 0; i < 12; i++) {
        fprintf(arquivo_texto, "%2d\t%d\n", i + 1, total_vendas_por_mes[i]);
    }

    // Fechar os arquivos
    fclose(arquivo_binario);
    fclose(arquivo_texto);

    // Liberar memória alocada
    free(vendas);
}

int main() {
    gerarRelatorio("vendas.bin", "totvendas.txt");
    return 0;
}
