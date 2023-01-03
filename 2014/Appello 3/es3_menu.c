
void vuild_menu(char **data[],int n){
    char **sol;
    sol=malloc(n*sizeof(*sol));
    pricipiodimoltiplicazione(0,data,sol,n);
}

void principiodimoltiplicazione(int pos, char **data[],char *sol[],int n){
    int i;
    if(pos>=n){
        printf("(");
        for(i=0;i<n;i++) printf("%s,",sol[i]);
        printf(")");
        return;
    }
    for(i=0;data[pos][i]!=NULL,i++){
        sol[pos]=strdup(data[pos][i]);
        principiodimoltiplicazione(pos+1,data,sol,n);
    }
}
