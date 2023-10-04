// 3) Fazer uma função que calcule e retorne como parâmetros os dois dígitos verificadores do cpf informado com parâmetro.
// Protótipo: void calc_digcpf(int cpfsemdigitos, int *dig1, int *dig2)

#include <stdio.h>
#include <stdlib.h>


void calc_digcpf(int cpfsemdigitos, int *dig1, int *dig2){
    cpfsemdigitos = 01953890008 // 11 numeros

    int soma1 =0, soma2 =0, digito, peso = 10;
    //calcular o primeiro digito

    for(int i = 0; i < 9; i++){
        digito = (cpfsemdigitos % 10); //pega o último dígito do "cpfsemdigitos"
        soma1 += (digito * peso); // acumulando a soma das multiplicações do dígito atual, o peso vai decrescendo a cada iteração
        cpfsemdigitos /= 10; // remove o último dígito do "cpf sem digitos"
        peso--; // diminui o peso de cada iteração
        
    }

    *dig1 = (soma1 % 11 < 2) ? 0 : (11 - (soma1 % 11)); 

    // Adiciona o primeiro dígito ao número para calcular o segundo dígito
    cpfsemdigitos = cpfsemdigitos * 10 + *dig1;
    peso = 11;
    
    //calcular o segundo digito 
    for (int i = 0; i < 10; i++) {
        digito = (cpfsemdigitos % 10);
        soma2 += (digito * peso);
        cpfsemdigitos /= 10;
        peso--;
    }
    *dig2 = (soma2 % 11 < 2) ? 0 : (11 - (soma2 % 11));

}
