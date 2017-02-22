#include <stdio.h>
//struct komplex {double re, im;};
//typedef struct komplex komplex;
typedef struct {double re, im;} komplex;

void init(komplex* z){
	(*z).re = 0; 	// * to make available outside.
	z->im = 1;		// -> is another notation for same thing.
}

int main(int argc, char const *argv[])
{
	komplex x = {.re=2,.im=3};
	x.re=0;
	init(&x); // need adress of x in order to change x to content of init().
	printf("\na = (%g,%g)\n",x.re,x.im);
	
	return 0;
}