#include<stdio.h>
#include<stdlib.h>

void init(int n, double* a){
	for(int i=0; i<n; i++) *(a+i)=1;
	}

int main(){
	int n=9;
//	double a[n];
	double* a = malloc(n*sizeof(double));
	init(n,a);
	printf("\na = ");
	for(int i=0; i<n; i++) printf("%g ",i[a]);
	printf("\n\n");

free(a);
return 0;
}