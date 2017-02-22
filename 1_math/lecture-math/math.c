#include <stdio.h>
#include <math.h>
#include <complex.h>

void hello();

int main(){

	hello();

	double x=5;
	double gx = tgamma(x);
	printf("gamma(%g)=%g\n\n",x,gx);

	x=-2;
	complex sqrx = csqrt(x);
	printf("csqrt(%g)=%g+i*%g\n\n",x,creal(sqrx),cimag(sqrx));

        printf("M_PI= %g\n",M_PI);
        printf("M_E = %g\n",M_E);
        printf("I   = %g+%gi\n",creal(I),cimag(I));

return 0;
}