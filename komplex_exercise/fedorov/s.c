#include<stdio.h>

typedef struct {double re, im;} komplex;

void init(komplex* z){
	(*z).re=0;
	z->im=1;
	}

int main(){
	komplex x = {.re=2,.im=3};
	x.re=0;
	init(&x);
	printf("\nx = (%g,%g)\n",x.re,x.im);
return 0;
}