// Faça uma função NaoNulos que recebe uma matriz de inteiros M[100][100] e aloca um vetor de naonulo de tamanho igual à quantidade de elementos diferentes de 0 na matriz, e coloca nele os elementos não nulos da matriz recebida, retornando, como valor de retorno da função, o pointer para o vetor alocado. Assuma que há pelo menos um elemento não nulo na matriz.
// Ex: se a função receber a mamtriz mostrada à esquerda, deve alocar e retronar o vetor de strucs à direita;

typedef struct naonulo{
    int valor;
    int linha;
    int coluna;
} tnaonulo;


tnaonulo *naoNulo( int M[100][100] ){

    int count = 0;
    tnaonulo nnaonulos[10000]; 
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if(M[i][j] != 0){
                nnaonulos[count].valor = M[i][j];
                nnaonulos[count].linha = i;
                nnaonulos[count].coluna = j;
                count++;
            }
        }
    }

    tnaonulo *p = (tnaonulo *)malloc(count * sizeof(tnaonulo));

    for (int i = 0; i < count; i++){
        p[i] =  nnaonulos[i];
    }
    
    return p;
}


tnaonulo *naoNulo( int M[100][100] ){

    int count = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if(M[i][j] != 0){
                count++;
            }
        }
    }

    tnaonulo *p = (tnaonulo *)malloc(count * sizeof(tnaonulo));

    int nn = 0;
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if(M[i][j] != 0){
                p[nn].valor = M[i][j];
                p[nn].linha = i;
                p[nn].coluna = j;
                nn++;
            }
        }
    }
    
    return p;
}
tnaonulo *naoNulo( int M[100][100] ){

    int count = 0;
    tnaonulo nnaonulos[10000]; 
    for (int i = 0; i < 100; i++){
        for (int j = 0; j < 100; j++){
            if(M[i][j] != 0){
                nnaonulos[count].valor = M[i][j];
                nnaonulos[count].linha = i;
                nnaonulos[count].coluna = j;
                count++;
            }
        }
    }

    tnaonulo *p = (tnaonulo *)malloc(count * sizeof(tnaonulo));

    for (int i = 0; i < count; i++){
        p[i] =  nnaonulos[i];
    }
    
    return p;
}
