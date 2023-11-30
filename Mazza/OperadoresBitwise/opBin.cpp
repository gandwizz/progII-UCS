#include <stdio.h>
void insere(unsigned int *conjunto, int valor)
{
unsigned int mascara=1<<valor;
*conjunto |= mascara;
}


void mostrabin(unsigned int conjunto)
{
int i;
for (i=31;i>=0;i--)
   printf("%d",conjunto>>i&1);
   
printf("\n");
}

int main() {
  unsigned int c=0;
  unsigned int x=0xF<<28 | 0xF;
  unsigned int x1 = x<<24;
  unsigned int x2 = x>>24;
  mostrabin(x1);
  mostrabin(x2);
  mostrabin(x1|x2);
  return 0;
}
