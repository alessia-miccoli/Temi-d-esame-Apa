/*
edges.txt:
14 5
0 1 2
0 2 3
0 3 1
1 2 1
2 3 1
3 4 1
2 4 2
1 0 2
2 0 3
3 0 1
2 1 1
3 2 1
4 3 1
4 2 2

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N INT_MAX

typedef struct lato
{
	int v;
	int w;
	int wt;
}edge;

edge* readfromfile(char* filename, int *dim,int *nv);
void powerset(int pos, edge* edgevet, int* sol, int* min, int* bestsol, int k,int dim,int v);
int check(int* sol, edge* edgevet, int k, int dim,int *ok,int v);


int main()
{
	int i;
	int dim,nv;
	edge* edgevet;
	edgevet = readfromfile("edges.txt", &dim,&nv);
	int* sol,*bestsol;
	sol = bestsol = calloc(dim, sizeof(int));
	int min = N;
	for (i = 0; i < dim; i++)
	{
		printf("%d %d %d\n", edgevet[i].v, edgevet[i].w, edgevet[i].wt);
	}
	printf("\n");
	powerset(0, edgevet, sol, &min, bestsol, dim, dim, nv );
	printf("%d", min);
}
edge* readfromfile(char* filename, int* dim,int *nv)
{
	edge* edgevet;
	int i,v,w,wt;
	FILE* fp;
	fp = fopen(filename, "r");
	fscanf(fp, "%d %d", dim,nv);
	edgevet = calloc(*dim, sizeof(edge));
	for (i = 0; i < *dim; i++)
	{
		fscanf(fp, "%d %d %d", &v, &w, &wt);
		edgevet[i].v = v;
		edgevet[i].w = w;
		edgevet[i].wt = wt;
	}
	return edgevet;
}
void powerset(int pos, edge* edgevet, int* sol, int* min, int* bestsol, int k, int dim,int v)
{
	int ok = 0, i,locmin;
	if (pos >= k)
	{
		locmin = check(sol, edgevet, k, dim, &ok,v);
		{
			if (ok)
			{
				if (locmin < * min)
				{
					*min = locmin;
					for (i = 0; i < k; i++)
						bestsol[i] = sol[i];
				}
			}
		}
		return;
	}

	sol[pos] = 0;
	powerset(pos + 1, edgevet, sol, min, bestsol, k, dim,v);
	sol[pos] = 1;
	powerset(pos+1, edgevet, sol, min, bestsol, k, dim,v);
}

int check(int* sol, edge* edgevet, int k, int dim, int* ok,int v)
{
	int min=0;
	int i,j,z,p,q,count=0,x;
	int* id;
	for (i = 0; i < k; i++)
	{
		if (sol[i] != 0)
			count++;
	}
	if (count == 0)
		return N;
	*ok = 1;
	id = malloc(v * sizeof(int));
	for (i = 0; i < v; i++)
	{
		id[i] = i;
	}
	for (z = 0; z < k; z++)
	{
		if (sol[z] != 0)
		{
			for (i = edgevet[z].v; i != id[i]; i = id[i]);
			for (j = edgevet[z].w; j != id[j]; j = id[j]);
			if (i != j)
				id[i] = j;
		}
	}
	x = id[0];
	for (i = 0; i < v; i++)
	{
		if (id[i] != x)
		{
			*ok = 0;
			break;
		}
	}
	if (*ok == 0)
		return N;
	
	for (i = 0; i < k; i++)
	{
		if (sol[i] != 0)
		{
			min = min + edgevet[i].wt;
		}
	}

	return min;

	
}
