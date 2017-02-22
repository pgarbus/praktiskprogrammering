#include <stdio.h> /*if angle brackets, looks in the current directory. 
otherwise look for standard library.*/
#include <tgmath.h>
void hello();
int main(){
	double x=5;
	double gx = tgamma(x);
	hello();
	printf("hello math: %g\n",x);
	printf("division 1/2 is %i\n",1/2);
	printf("division 1.0/2.0 is %g\n",1.0/2.0);
	printf("Calculating gamma(%g) = %g\n",x,tgamma(x));
	double y=0.5;
	printf("Calculating first-order bessel(%g) = %g\n",y,j1(y));
	double z = -2;
	printf("csqrt(%g) = %g + %gi\n",z,creal(csqrt(z)),cimag(csqrt(z)));
	double complex w = 0 + 1*I;
	printf("exp(i) = %g + %gi\n",creal(exp(w)),cimag(exp(w)));
	printf("exp(i*PI) = %g + %gi\n",creal(exp(w*M_PI)),cimag(exp(w*M_PI)));
	printf("exp(0) = %g\n",exp(0));
	printf("i power epsilon = %g + %gi\n",creal(pow(I,M_E)),cimag(pow(I,M_E)));
	float floatvar = 0.1111111111111111111111111111;
	double doublevar = 0.1111111111111111111111111111;
	long double longvar = 0.1111111111111111111111111111L;
	printf("float %.25g\n", floatvar);
	printf("double %.25lg\n", doublevar);
	printf("long double %.25Lg\n", longvar);
	return 0;
}
void hello(){printf("hello\n");}
/*To compile program, use "cc show.c -o show | ./show"

cc -c math.c
cc math.o
./a.out

cc math.o hello.o -o -lm math // to link more files. -lm links to math library.

%g is general placeholder.

one step: cc math.c
*/

