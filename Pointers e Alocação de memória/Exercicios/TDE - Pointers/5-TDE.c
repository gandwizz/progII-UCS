// 5) Fazer uma função que copie da string origem para a string destino somente os dígitos, os demais caracteres não devem ser copiados. O apontador para a string destino deverá ser também o retorno da função.
// Protótipo: char *copiadigitos(char *destino, char *origem)

char *copiadigitos(char *destino, char *origem){

    int j = 0; //controle de adicionais de digitos na string destino
    for(int i = 0; i < strlen(origem); i++){
        if(origem[i] >= '0' && origem[i]<= '9'){
            destino[j] = origem[i];
            j++;
        }
    }

    destino[j]  = '\0';
    return destino;
}
