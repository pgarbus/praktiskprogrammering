#include<stdio.h>

void init(double* u){ *u=1; }

int main(){
	double x = 1.23;
	init(&x);
	printf("\nx=%g\n\n",x);
	

return 0;
}