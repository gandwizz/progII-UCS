1)
void copiastring (char st[], char m[10][10],int lin, int col) {
    int i;
    for (i=0, st[i]!='\0', i++) {
        M[lin][col] = st[i];
        col++;
        if (col==15) {col=0; lin++}
        if (lin == 15) {return;}
    }
}

2)
for (i =0, i<10; i++) {
    cm =0;
    for (j=1; j<110; j++) 
    if(n[i][j] < m[i][cm])
    {
        cm = j;
    }
}

3)
void codifica (char st1[], char st2[]) {
    int i2 = 0;
    quant = 1,

    for (i=0; st[1]!='\0', i++) {
        if ( st[i] == st[i-1]) {
            quant ++
        } else {
            st2[i2] = quant + '0';
            st2[i2 + 1] = st [i-1];
            i2 += 2;
        }
    }
    st2[i2]='\0'
}