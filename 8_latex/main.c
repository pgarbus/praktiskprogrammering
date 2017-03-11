#include <stdio.h>
#include <gsl/gsl_integration.h>
#include <gsl/gsl_errno.h>
#include <math.h>


/*

    Implement the error-function by integrating (= finding the solution) 
    numerically the differential equation

    u'(x) = (2/√π) e-x²

    with the initial condition

    u(0) = 0 .

    Make a plot of your error function in PDF or LaTeX format. Your main 
    function must take three command-line arguments — let us call them a, 
    b, and dx — and it must write (to the standard output) a table of 
    error-function values from a to b with step dx. The command in the 
    Makefile should be something like

    ./main -3 3 0.2 > data.txt

    Make a one- or two-page report, in LaTeX, about the error function 
    using the material from the corresponding article in Wikipedia.
    
    Include your plot in the report. 
*/

// int diff_func(double t, const double y[], double f[], void* params);


double err_func_helper(double x, void* params){
	// the error function, https://en.wikipedia.org/wiki/Error_function
	double dydx = (2/sqrt(M_PI))*exp(-pow(x,2));
	return dydx;
}

double err_func_handler(double x){
	size_t allocated = 1000; // what is the effect of allocated?
	gsl_integration_workspace* w = gsl_integration_workspace_alloc(allocated);
	double result, error;
	gsl_function F;
	F.function = &err_func_helper;
	F.params = NULL;
	// int gsl_integration_qags (
		// const gsl_function * f, 
		// double a, double b, 
		// double epsabs, double epsrel, 
		// size_t limit, gsl_integration_workspace * workspace, 
		// double * result, double * abserr)
	double a = 0 /*start*/, b = x /*finish*/;
	double epsabs = 0, epsrel = 1e-7;
	gsl_integration_qags(&F, a, b, epsabs, epsrel, allocated, w, &result, &error); 
	gsl_integration_workspace_free (w);
	return result;
}



int main(int argc, char* argv[])
{
	// printf("Hello world\n");

	// printf("The first value of argv is argv[0] = %s\n",argv[0]);
	double input[3];
	for (int i = 1; i < argc; ++i)
	{
		input[i-1] = atof(argv[i]);
		// printf("%g\n", atof(argv[i]));
	}
	double a = input[0], b=input[1], dx=input[2];
	for (double i = a; i < b; i+=dx)
	{
		double result = err_func_handler(i);
		printf("%16lg %16lg\n",i,result);
	}
	return 0;
}