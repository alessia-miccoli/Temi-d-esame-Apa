#include <stdlib.h>
#include <stdio.h>

#define M 8

void comb_rip(int pos, int *sol, int *lunghezza, int *prezzo, int n, int k, int start, int lungMax, 
              int lungTot, int prezzoTot, int *bestSol, int *bestPrezzo, int *nPezzi){
	int i;

	if(pos >= k){
        if(lungTot == lungMax){
            if(prezzoTot > *bestPrezzo){
                *nPezzi = k;
                *bestPrezzo = prezzoTot;
                for(i=0; i < k; i++) bestSol[i] = lunghezza[sol[i]];
            }
        }
		return;
	}

	for(i=start; i < n; i++){
		if((lungTot + lunghezza[i]) <= lungMax){
			sol[pos] = i;
			lungTot += lunghezza[i];
			prezzoTot += prezzo[i];

			comb_rip(pos+1, sol, lunghezza, prezzo, n, k, start, lungMax, lungTot, prezzoTot, bestSol, bestPrezzo, nPezzi);

			lungTot -= lunghezza[i];
			prezzoTot -= prezzo[i];
			start++;
		}
	}
}

void maxPrezzoTagli(int lungMax, int m, int *lunghezze, int *prezzi){
	int k, bestPrezzo = 0, nPezzi = 0;
	int *sol, *bestSol;

	bestSol = malloc(lungMax * sizeof(int));
	sol = malloc(lungMax * sizeof(int));

    for(k=1; k <= lungMax; k++){
        comb_rip(0, sol, lunghezze, prezzi, m, k, 0, lungMax, 0, 0, bestSol, &bestPrezzo, &nPezzi);
    }
	printf("La soluzione ottima e' con %d tagli che genera %d pezzi e ha valore %d\n", nPezzi-1, nPezzi, bestPrezzo);
	//for(k=0; k < nPezzi; k++) printf("%d ", bestSol[k]);
}


int main(){
	int lunghezza[M] = { 7, 4, 8, 1, 5, 2, 6, 3 };
	int prezzo[M] = { 17, 9, 20, 2, 10, 5, 17, 8 };
 	int n = 4;

	maxPrezzoTagli(n, M, lunghezza, prezzo);

	return 0;
}
