#include <stdio.h>
#include <math.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_integration.h>

double f(double x, void *params){
	double alpha = *(double *) params;
	double f = log(alpha*x)/sqrt(x);
	return f;
}

int main(void){
	size_t allocated = 1000;
	double result, error, alpha = 1.0;
	double start = 0, end = 1;
	double epsabs = 0, epsrel = 1e-7;

	gsl_function F;
	F.function = &f;
	F.params = &alpha;

	gsl_integration_workspace* w = gsl_integration_workspace_alloc(allocated);

	int status = gsl_integration_qags(&F, start, end, epsabs, epsrel, allocated, w, &result, &error); 

	gsl_integration_workspace_free(w);
	if(status==GSL_SUCCESS){
		fprintf(stderr, "Finished integration\n");
		fprintf(stderr, "area = %lg, error = %i\n", result, status);
	}
	
	double x, dx = 0.01;
	for (x = 0.0; x < 1; x+=dx)
	{
		double result = f(x,&alpha);
		printf("%8.5lg %8.5lg\n", x, result);
	}
	return 0;
}