#include<stdio.h>

void print_f_of_1( double (*f)(double) ){
		double y=f(1);
		printf("f_of_1 = %g\n",y);
		}