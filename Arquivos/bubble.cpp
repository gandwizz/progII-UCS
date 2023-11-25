#include <stdio.h>

int main()
{
FILE *arqin=fopen("dados.dat","r+b");

int v1,v2,trocou=1;

while (trocou){
trocou=0;

fseek(arqin,0L,SEEK_SET);
fread(&v1,sizeof(int),1,arqin);
while (fread(&v2,sizeof(int),1,arqin))
	{
	if (v1>v2)
		{
		fseek(arqin,-8L,SEEK_CUR);
		fwrite(&v2,sizeof(int),1,arqin);	
		fwrite(&v1,sizeof(int),1,arqin);	
		fflush(arqin);
		trocou=1;
		}
	else 
        v1=v2;
	}
}
fclose(arqin);
}
