// I 2) Fa¸ca uma fun¸c˜ao que receba uma data, formada por dia, mˆes e
// ano, e retorne, nos mesmos parˆametros, a data do dia seguinte.
// Considere que ano bisexto ´e aquele divis´ıvel por 4. Considere
// tamb´em que abril, junho, setembro e novembro tem 30 dias,
// fevereiro tem 28 (29 se o ano for bisexto) e todos os outros meses
// tem 31 dias.



#include <stdio.h>
struct horario {
    int h;
    int m;
    int s;
};
 
void segundoseguinte (struct horario *t){
    (*t).s++;
   
    if ((*t)s == 60) {
        
        (*t).s = 0;
        (*t).m++;
        
        if ((*t).m == 60) {
            
            (*t).m=0;
            (*t).h++;
            
            if ((*t).h == 24) t->h=0;
        }         
    } 
}

int main() {
    struct horario t;
    t.h = 20;
    t.m = 20;
    t.s =  20;

    segundoseguinte(&t);

    printf("%d:%d:%d", t.h,t.m,t.s);

}
    
    
    