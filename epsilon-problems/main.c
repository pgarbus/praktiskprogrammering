#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#define TINY 1e-6
int main(int argc, char const *argv[])
{
	// exercise 1
	/*calc_int_max();
	calc_int_min();
	epsilon_float();
	epsilon_double();
	epsilon_longdouble();
	*/

	// exercise 2 // result does not make sense... no difference.
	/*
	*/
	int max = INT_MAX/100;
	sum_up_float(max);
	sum_down_float(max); // returns an error if func 
						// is defined as double (as it returns...)
	
	
	// exercise 3
	double a = 1.0, b = 1.7, tau = TINY, epsilon = TINY; 
	printf("lg %lg\n", tau);
	int answer = equal(a,b,tau,epsilon); 
	printf("answer from equal function = %i\n", answer);
	return 0;
}
int equal(double a, double b, double tau, double epsilon){
	double c = a-b; double d = labs(a-b); double e = labs(a)+labs(b);
	printf("%lg %lg %lg %lg %i\n",c, d, e, d/e, d/e < epsilon/2);
	int boolean = (d/e < epsilon/2);
	printf("%lg %i\n", d/e, boolean);
	if ((double)labs(a-b) < tau) {printf("should not print tau\n");return 1;}
	if (0) {printf("should not print epsilon\n"); return 1;}
	else {return 0;}
}
int sum_up_float(int max){
	double limit = 0.0f;
	for (int i = 1; i <= max; ++i)
	{
		// printf("limit\t%g\t\ti\t%i\n",limit,i);
		limit += (float)1.0/i;
	}
	printf("limit of sum_up_float with \tmax %i is %g.\n", max, limit);
	return limit;
}
int sum_down_float(int max){
	double limit = 0;
	for (int i=0; i<max; i++){
		// printf("limit\t%g\t\ti\t%i\n",limit,i);
		limit += (float)1.0/(max-i);
		// printf("limit\t%g\t\ti\t%i\n",limit,i);
	}
	printf("Limit of sum_down_float with \tmax %i is %g.\n",max,limit);
	return limit;
}
void epsilon_longdouble(){
	long double i=1;
	while(1+i!=1){i/=2;}
	i*=2;
	printf("Long double: Machine epsilon =\t %Lg\n", i);
	printf("System LDBL_EPSILON = \t\t %Lg\n", LDBL_EPSILON);
}
void epsilon_double(){
	double i = 1;
	while(1+i != 1){i/=2;}
	i*=2;
	printf("Double: Machine Epsilon=\t %lg\n", i);
	printf("System DBL_EPSILON = \t\t %lg\n", DBL_EPSILON);
}
void epsilon_float(){
	float i = 1;
	while(1+i != 1){i/=2;}
	i*=2;
	printf("Float: Machine Epsilon =\t %g\n",i);
	printf("System FLT_EPSILON = \t\t %g\n", FLT_EPSILON);
}
void calc_int_max(){
	printf("the system-defined INT_MAX is\t\t %i\n", INT_MAX);
	int i=1;while (i < 1+i) {++i;}
	printf("while-loop: The largest value of i =\t %i\n",i);
	for(i = 1;i+1>i;++i) {;}
	printf("for-loop: the largest value of i =\t %i\n", i);
	i=1;
	do
	{
		++i;
	} while (i+1>i);
	printf("do-loop: the largest value of i =\t %i\n", i);
}
void calc_int_min(){
	printf("The system smallest value is\t\t %i\n", INT_MIN);
	int i = 0;
	while (i-1<i) {--i;}
	printf("while-loop: The smallest value of i =\t %i\n", i);
	for (i = 0; i-1 < i; --i) {;}
		printf("for-loop: The smallest value of i =\t %i\n", i);
	i=0;
	do
	{
		--i;
	} while (i-1<i);
	printf("Do-loop: The smallest value of i =\t %i\n", i);
	
}