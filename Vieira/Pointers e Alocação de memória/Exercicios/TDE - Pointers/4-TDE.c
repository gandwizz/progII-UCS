// 4) Faça uma função que receba como parâmetro uma matriz M[5][5] e retorne o maior valor existente na matriz, bem como a linha e coluna onde o valor ocorre.


void maiorNumero ( int M[5][5], int *maior, int*linha, int*coluna){
    *maior = M[0][0];

    for(int i = 0; i<5; i++){
        for(int j = i+1; j<5; j++){

            if(M[i][j] > *maior){
                *maior = M[i][j];
                *linha = i;
                *coluna = j;
            }
        }
    }

}