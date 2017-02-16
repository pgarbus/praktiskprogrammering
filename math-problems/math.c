#include <stdio.h>
#include <math.h>
#include <complex.h>

void hello();

int main(){
	hello();
	double x=5;
	double gam=gamma(x);
	printf("gamme(5) = %g\n",gam);
	double bes=j1(x/10);
	printf("bessel1(0.5) = %g\n",bes);
	x = -2;
	complex sqrt = csqrt(x);
	printf("csqrt(%g) = %g + i*%g\n",x, creal(sqrt),cimag(sqrt));
	complex y = I*1;
	complex exp = cexp(y);
	printf("cexp(i*%g) = %g + i*%g\n",cimag(y),creal(exp),cimag(exp));
	complex z = y*M_PI;
	exp = cexp(z);
	printf("cexp(i*%g) = %g + i*%g\n",cimag(z),creal(exp),cimag(exp));
	complex poww = pow(y,M_E);
	printf("pow(i*%g,%g) = %g + i*%g\n",cimag(y),M_E,creal(poww),cimag(poww));
	float float_num = 0.1111111111111111111111111111;
	double double_num = 0.1111111111111111111111111111;
	long double longdouble_num = 0.1111111111111111111111111111L;
	printf("float\n%.25g\ndouble\n%.25lg\nlong double\n%.25Lg\n", float_num,double_num,longdouble_num);
	return 0;
}
/*
void print_(double var){
	printf("Your int value is %g",var);
}
*/