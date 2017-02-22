#include <stdio.h>
#include <math.h>
double square(double x){return x*x;}
void print_f_of_1(double (*f)(double)) {
	double y=f(1);
	printf("f_of_1 = %g\n", f(1));
}
int main(){
	double (*f[3])(double) = {sin,cos,tan}; // pointer to function, argument is double. double*f would refer pointer to double.
	for (int i = 0; i < 3; i++) printf("f[%i](%g)\n",i, f[i](1));
	
	struct funs {double (*a)(double); double(*b)(double);};
	struct funs F = {.a=sin,.b=cos};
	printf("%g %g\n", F.a(1), F.b(1));

	// f=square; // Fedorov doesnt know why this works...
	printf("%g\n", f(2));
	print_f_of_1(sin);
	print_f_of_1(cos);
	print_f_of_1(tan);
	print_f_of_1(erf);
	return 0;
}