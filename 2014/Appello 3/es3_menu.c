#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 3

void initialize_data(char **data[]);
void principiodimoltiplicazione(int pos, char **data[],char *sol[],int n);
void build_menu(char **data[], int n);

int main()
{
    char **data[N];

    initialize_data(data);
    build_menu(data,N);

    return 0;
}

void initialize_data(char **data[]){

    data[0] = malloc(3*sizeof(char*));
    data[0][0] = strdup("pasta");
    data[0][1] = strdup("riso");
    data[0][2] = NULL;

    data[1] = malloc(4*sizeof(char*));
    data[1][0] = strdup("carne");
    data[1][1] = strdup("pesce");
    data[1][2] = strdup("formaggio");
    data[1][3] = NULL;

    data[2] = malloc(3*sizeof(char*));
    data[2][0] = strdup("gelato");
    data[2][1] = strdup("torta");
    data[2][2] = NULL;

    return;
}


void build_menu(char **data[],int n){
    char **sol;
    sol=malloc(n*sizeof(*sol));
    principiodimoltiplicazione(0,data,sol,n);
}

void principiodimoltiplicazione(int pos, char **data[],char *sol[],int n){
    int i;
    if(pos>=n){
        printf("(");
        for(i=0;i<n;i++) printf("%s,",sol[i]);
        printf(")");
        return;
    }
    for(i=0;data[pos][i]!=NULL;i++){
        sol[pos]=strdup(data[pos][i]);
        principiodimoltiplicazione(pos+1,data,sol,n);
    }
}
