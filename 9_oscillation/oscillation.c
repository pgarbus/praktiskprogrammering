#include <gsl/gsl_errno.h>
#include <gsl/gsl_integration.h>
#include <math.h>
#include <assert.h>

// hamil = -0.5 * d'' + 0.5 * x * x
double gaussian(double x, void *params){
	double alpha = *(double *) params;
	return exp(-alpha * x * x) * 0.5 * (pow(x,2) + alpha - pow(alpha,2)*pow(x,2));
}

double norm(double x, void* params){
	double alpha = *(double *) params;
	return exp(-alpha * x * x);
}


double E(double alpha){
	assert(alpha > 0);
	const size_t limit = 100;
	const double epsabs = 1e-7, epsrel = 1e-7;
	double nume_result, nume_error;
	double deno_result, deno_error;

	gsl_function nume;
	nume.function = &gaussian;
	nume.params = &alpha;

	gsl_function deno;
	deno.function = &norm;
	deno.params = &alpha;

	gsl_integration_workspace* w = gsl_integration_workspace_alloc(limit);

	// int gsl_integration_qagi (gsl_function * f, 
	// double epsabs, double epsrel, size_t limit, 
	// gsl_integration_workspace * workspace, double * result, double * abserr)

	int nume_status = gsl_integration_qagi(
		&nume, 
		epsabs, 
		epsrel, 
		limit, 
		w, 
		&nume_result, 
		&nume_error); 

	int deno_status = gsl_integration_qagi(
		&deno, 
		epsabs, 
		epsrel, 
		limit, 
		w, 
		&deno_result, 
		&deno_error); 

	gsl_integration_workspace_free(w);

	if(deno_status==GSL_SUCCESS && nume_status == GSL_SUCCESS) return nume_result / deno_result;
	else return NAN;
}