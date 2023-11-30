#include <stdio.h>
#include <stdlib.h>

int comp( const void *a, const void*b){
    if( *(int*)a > *(int*)b) return 1;
    if( *(int*)a < *(int*)b) return -1;
    return 0;
}

int main(){
    int m[5]={5,1,2,3,4};
    qsort(m, 5, sizeof(int), comp);
    return 0;

}