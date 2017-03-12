#include <gls/gsl_integration.h>
#include <math.h>

double f(double x, void *params){
	double alpha = *(double *) params;
	double f = log(alpha*x)/sqrt(x);
	return f;
}