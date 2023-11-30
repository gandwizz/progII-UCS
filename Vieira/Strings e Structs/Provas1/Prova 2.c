1)
void soma (char m[5][5],int li, int ci, int lf, int cf) {
    int i;
    while(li<lf || li == lf && ci <= cf)
    {
        s += M[li][ci];
        ci++;
        if( ci == 10) {
            ci =0;
            li++
        }
    
    }
}

2)
int contamin (char st[]) {
    char c;
    int cont = 0;
    for (c='a'; cc='z'; c++) {
        tem =0;
        if (st[i] == c) tam =1;
        cont+=tem
    }

    

}

2) 
int vf [26] = {0};
    for (i=0; st[i]!= '\0'; i++)
    if (st[1] >= 'a' && st[i]<='z')
        vf[st[i]-'a'] = 1;


3)
void ordena (tpessoa p[10]) {

    for (int i = 0; i<9; i++) {
        for (int j = 0; j<9; j++) {
            if (p[i].idade > p[j].idade) {

                tpessoa aux = p[i];
                p[i] = p[j];
                p[j] = aux;

            } else if (p[i].idade == p[j].idade) {

                if (strcmp(p[i.nome], p[j].nome) > 0) {

                    tpessoa aux = p[i];
                    p[i] = p[j];
                    p[j] = aux;

                }
                
            }

        }

    }
}