
#include <stdio.h>
 
 
void segundoseguinte (int *h, int *m,int *s){
    int ssoma = *s;
    int msoma = *m;
    int hsoma = *h;
 
    ssoma++;
   
    if (ssoma == 60) {
        
        *s = 0;
        msoma++;

        if (msoma == 60) {
            
            *m=0;
            hsoma++;
            
            *h = hsoma;
        } else {
            
            *m = msoma;
            
        }

        
    } else {
        
     *s = ssoma;

    }
}

int main() {
    int h,m,s;
    
    h = 10;
    m = 59;
    s = 59;
    
    segundoseguinte(&h,&m,&s);

    printf("%d:%d:%d", h,m,s);

}
    
    