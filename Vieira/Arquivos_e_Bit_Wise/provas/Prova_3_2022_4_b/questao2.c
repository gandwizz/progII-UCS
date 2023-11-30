
// (3.3 pontos) Faça uma função que receba uma matriz M[4][4] de inteiros iguais a 0 ou 1, e retorne um inteiro de 16 bits
// sem sinal em que cada bit contem o valor correspondente a uma posição da matriz. O bit 15 deve conter o valor da posição
// m[0][0] e o bit 0 deve conter o valor da posição [3][3]. Ex: Se a matriz M contem:
// 0 1 0 1
// 1 1 1 1
// 0 1 0 1
// 0 0 0 0
// A função deve retornar o valor inteiro correspondente ao binário    0101 1111 0101 0000.

unsigned int matrizBinario( int m[4][4]){

    unsigned int binario = 0;

    int cont = 0;
    for(int i = 3; i>=0; i--){
        for(int j = 3; j>=0; j--){
        
            if(m[i][j] == 1){
                unsigned int mascara = 1<<cont;

                binario |= mascara;
            }
            cont++;

        }
    }

    return binario;


}


int main(){

    int m[4][4] = {{0,1,0,1},{1,1,1,1},{0,1,0,1},{0,0,0,0}};
        
    matrizBinario(m);

    return 0;
}