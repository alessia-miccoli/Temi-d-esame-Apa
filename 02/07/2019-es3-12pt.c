#include <stdlib.h>
#include <stdio.h>

#define N 9

int check(int *sol, int *val, int n, int *dim){

	int i, cnt, cresc, decresc;
	int *tmp = malloc(n * sizeof(int));

	for(i=0, cnt=0; i < n; i++) if(sol[i]) tmp[cnt++] = val[i];

	for(i=0, cresc = 0, decresc = 0; i < cnt-1; i++){
		//CASO decresc = cresc = 0
		if(!i){
			if(tmp[i+1] > tmp[i]){
				cresc = 1;
			}else{
				decresc = 1;
			}
		}
		if(cresc && !decresc && tmp[i+1] < tmp[i])
			decresc = 2;
		if(decresc && !cresc && tmp[i+1] > tmp[i])
			cresc = 2;
		if(decresc == 2 && tmp[i+1] > tmp[i])
			return 0;
		if(cresc == 2 && tmp[i+1] < tmp[i])
			return 0;
	}

	if(cnt < *dim) return 0;

	*dim = cnt;
	return 1;
}

void powerSet(int pos, int *val, int *sol, int n, int *bestSol, int *dim ){
	int i, j;
	if(pos >= n){
		if(check(sol, val, n, dim)){
			for(i = 0, j = 0; i < n; i++) if(sol[i]) bestSol[j++] = val[i];
		}
		return;
	}
	sol[pos] = 0;
	powerSet(pos+1, val, sol, n, bestSol, dim);
	sol[pos] = 1;
	powerSet(pos+1, val, sol, n, bestSol, dim);
}

void seqBitonica(int *val, int n){
	int i, dim = 0;
	int *sol, *bestSol;
	sol = malloc(n*sizeof(int));
	bestSol = malloc(n*sizeof(int));

	powerSet(0, val, sol, n, bestSol, &dim);

	printf("Una sottosequenza Bitonica di lunghezza massima %d e':\n", dim);
	for(i=0; i < dim; i++) printf("%d ", bestSol[i]);
}

int main(){

	int vect[N] = { 4, 2, 5, 9, 7, 6, 10, 3, 1 };

	seqBitonica(vect, N);

	return 0;
}
