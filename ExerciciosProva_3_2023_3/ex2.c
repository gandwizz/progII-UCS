#include <stdio.h>
#include <stdlib.h>
void inverte(unsigned short *conjunto)
{
    unsigned short mascara;
    int i, j;
    unsigned short maux = 0;
    for(i=0, j=15;i<16;i++, j--){
        mascara=0;
        mascara |= (1<<i);
        if((*conjunto&mascara)!=0)
            maux |= (1<<j);
    }
    *conjunto=maux;
}

void mostrabin(unsigned short conjunto){
	int i;
	for (i=15;i>=0;i--) {
		printf("%d", conjunto >> i&1);
	}
}

int main()
{
    unsigned short conjunto = 15;  
    mostrabin(conjunto);
    printf("\n");
    inverte (&conjunto);
    mostrabin(conjunto);
}
