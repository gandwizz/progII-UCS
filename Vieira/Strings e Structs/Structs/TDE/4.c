// 4) Faça um programa que leia uma frase com no máximo 100 palavras de tamanho não maior que 20, e escreva a lista de palavras diferentes da frase, com o número de ocorrências de cada palavra, em ordem alfabética. Considere que o string contem somente as palavras, separadas por espaços em branco, sem qualquer outro caracter de pontuação.

#include <stdio.h>
#include <string.h>

int main()
{
    char palavras[100][20];
    int contagem[100] = {0};
    int total_palavras = 0;

    char frase[2101];
    fgets(frase, sizeof(frase), stdin);
    char *p=strtok(frase," ");

    while (p && total_palavras < 100)
    {
        int palavra_existente = 0;

    // Aqui ele vai percorrer todas as palavras do array palavras, e ver se elas são iguais ou não. Caso forem, conta +1 na contagem referente a posição dela
        for (int i = 0; i < total_palavras; i++) {
            if (strcmp(p, palavras[i]) == 0) {
                palavra_existente = 1;
                contagem[i]++;
                break;
            }
        }

    // Salva uma palavra que não existe no array de palavras, e coloca o valor de 1 pra ela
        if (!palavra_existente) {
            strncpy(palavras[total_palavras], p, 20);
            contagem[total_palavras] = 1;
            total_palavras++;
        }

        p=strtok(NULL, " ");
    }


    // Ordenar as palavras por ordem alfabética

    for (int i = 0; i < total_palavras; i++)
    {
        for (int j = 0; j < total_palavras; j++)
        {
            if (strcmp(palavras[i],palavras[j]) > 0)
            {
                char palavra_aux[20];
                strcpy(palavra_aux, palavras[i]);
                strcpy(palavras[i], palavras[j]);
                strcpy(palavras[j], palavra_aux);
                
                int temp_count = contagem[i];
                contagem[i] = contagem[j];
                contagem[j] = temp_count;
            }
            
        }
    }

    for (int i = 0; i < total_palavras; i++)
    {
        printf("%s: %d\n", palavras[i], contagem[i]);
    }
    
    
    return 0;
}
