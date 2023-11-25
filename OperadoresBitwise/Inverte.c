#include <stdio.h>
#include <stdlib.h>
void inverte(unsigned int *conjunto)
{
    unsigned int mascara;
    int i, j;
    unsigned int maux = 0b0000000000000000;
    for(i=0, j=15;i<16;i++, j--){
        mascara=0;
        mascara |= (1<<i);
        if((*conjunto&mascara)!=0)
		    maux |= (1<<j);
    }
    *conjunto=maux;
}

void mostrabin(unsigned int conjunto){
	int i;
	for (i=31;i>=0;i--) {
		printf("%d", conjunto >> i&1);
	}
}

int main()
{
    unsigned int conjunto = 0b0100001110000001;  
    mostrabin(conjunto);
    printf("\n");
    inverte (&conjunto);
    mostrabin(conjunto);
}
