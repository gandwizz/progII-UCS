#include <stdio.h>
char *ConvParaBin(char s[], unsigned int numero) {
    int i=1;
    while(numero>>i){
        i++;
    } 
    s[i]='\0';
    i--;
    while(i>=0) {
        s[i]= (numero&1) + '0';
        numero >>= 1;
        i--;
    }
    return s;
}
int main()
{
    char c[10];
    unsigned int n = 5;
    printf("%s", ConvParaBin(c, n));
}
