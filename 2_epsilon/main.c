#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#define TINY 1e-6
int epsilon_float();
void calc_int_max();
void calc_int_min();
void epsilon_double();
void epsilon_longdouble();
int sum_up_float();
int sum_down_float();
int equal();



int main(void)
{
	{ /*question 6*/
		printf("question 6\n");
		int i=1; 
		printf("Initialize i = %i\n", i);
		printf("%i the i++ is carried out after printf\n",i++); 
		printf("%i the ++i is carried out before printf\n\n",++i);
	}

	{ /*question 7*/
		printf("question 7\n");
		int i=1; 
		printf("Initialized i = %i. the next printf is with i++ and ++i\n", i);
		printf("%i ++i already executed, i++ will be after this print. %i both i++ and ++i executed.\n",i++,++i);
		printf("Another result can be obtained if the optimization -o option is applied in the Makefile.\n");
	}

	/*exercise 1*/
	printf("\nEXERCISE 1: even with optimization -o the computation takes a long time\n");
	printf("Finding the largest machine integer\n");
	calc_int_max(); // do not call, take a long time to process

	printf("\nFinding the smallest machine interger\n");
	calc_int_min(); // do not call, take a long time to process.

	printf("\nOn the machine epsilon and more\n");
	epsilon_float();
	epsilon_double();
	epsilon_longdouble();
	

	// exercise 2 // .
	printf("\nEXERCISE 2\n");
	int max = INT_MAX/100;
	sum_up_float(max);
	sum_down_float(max);
	
	
	// exercise 3
	printf("\nEXERCISE 3\n");
	double a = 1.0, b = 1.7, tau = TINY, epsilon = TINY; 
	printf("long float of tau = %lg\n", tau);
	int answer = equal(a,b,tau,epsilon); 
	printf("answer from equal function = %i\n", answer);
	return 0;
}
/*In C the helper functions do not need to be defined before the main function*/
int equal(double a, double b, double tau, double epsilon){
	double c = a-b; double d = fabs(a-b); double e = fabs(a)+fabs(b);
	printf("c=%lg d=%lg e=%lg d/e=%lg d/e < epsilon/2 = %i\n",c, d, e, d/e, d/e < epsilon/2);
	int boolean = (d/e < epsilon/2);
	printf("d/e=%lg d/e < epsilon/2=%i\n", d/e, boolean);
	if ((double)fabs(a-b) < tau) {printf("should not print tau\n");return 1;}
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
int epsilon_float(){
	float i = 1;
	while(1+i != 1){i/=2;}
	i*=2;
	printf("Float: Machine Epsilon =\t %g\n",i);
	printf("System FLT_EPSILON = \t\t %g\n", FLT_EPSILON);
	return 0;
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
	// return 0;
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