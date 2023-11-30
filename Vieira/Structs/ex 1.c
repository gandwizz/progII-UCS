
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
    


// I 2) Fa¸ca uma fun¸c˜ao que receba uma data, formada por dia, mˆes e
// ano, e retorne, nos mesmos parˆametros, a data do dia seguinte.
// Considere que ano bisexto ´e aquele divis´ıvel por 4. Considere
// tamb´em que abril, junho, setembro e novembro tem 30 dias,
// fevereiro tem 28 (29 se o ano for bisexto) e todos os outros meses
// tem 31 dias.



// #include <stdio.h>
// struct horario {
//     int h;
//     int m;
//     int s;
// };
 
// void segundoseguinte (struct horario *t){
//     (*t).s++;
   
//     if ((*t)s == 60) {
        
//         (*t).s = 0;
//         (*t).m++;
        
//         if ((*t).m == 60) {
            
//             (*t).m=0;
//             (*t).h++;
            
//             if ((*t).h == 24) t->h=0;
//         }         
//     } 
// }

// int main() {
//     struct horario t;
//     t.h = 20;
//     t.m = 20;
//     t.s =  20;

//     segundoseguinte(&t);

//     printf("%d:%d:%d", t.h,t.m,t.s);

// }