#include <stdio.h>
#include <math.h>
#include <gsl/gsl_multimin.h>

/*
least square fit:
f(t)=A*exp(-t/T)+B
minimize:
F(A,T,B)=∑i(f(ti)-yi)²/σi²
*/

struct experimental_data {int n; double *t, *y, *e;};

double decay_function_to_plot(double t, const gsl_vector *variables){
	double A= gsl_vector_get(variables,0);
	double T= gsl_vector_get(variables,1);
	double B= gsl_vector_get(variables,2);
	return A*exp(-t/T) + B;
}

double function_to_minimize(const gsl_vector *start, void *params){
	double A= gsl_vector_get(start,0);
	double T= gsl_vector_get(start,1);
	double B= gsl_vector_get(start,2);
	struct experimental_data *data = (struct experimental_data*) params;

	int n = data->n;
	double *t = data->t;
	double *y = data->y;
	double *e = data->e;
	double functions = 0;
	#define f(t) A*exp(-t/T) + B
	for(int i = 0; i < n; i++) functions += pow((f(t[i]) - y[i])/e[i],2);
	return functions;
}




int main(void)
{
	struct experimental_data all_data;

	double t[]= {0.47,1.41,2.36,3.30,4.24,5.18,6.13,7.07,8.01,8.95};
	double y[]= {5.49,4.08,3.54,2.61,2.09,1.91,1.55,1.47,1.45,1.25};
	double e[]= {0.26,0.12,0.27,0.10,0.15,0.11,0.13,0.07,0.15,0.09};
	int n = sizeof(t)/sizeof(t[0]);

	all_data.t = t;
	all_data.y = y;
	all_data.e = e;
	all_data.n = n;


	/*the iterator bookkeeper*/
	size_t iter = 0;
	/*returned status from gsl_fminimizer.*/
	int status;
	/*dimension of parameter space*/
	size_t dim = 3;
	/*initialize starting point vector*/
	gsl_vector *start;
	start = gsl_vector_alloc(3);
	/*starting points*/
	gsl_vector_set(start, 0, 1);
	gsl_vector_set(start, 1, 1);
	gsl_vector_set(start, 2, 1);
	/*initial stepping size*/
	gsl_vector *step = gsl_vector_alloc(3);
	gsl_vector_set_all(step,1.0);
	/*initilize function to minimize*/
	gsl_multimin_function minimization = 
		{.n = dim, .f=function_to_minimize, .params=&all_data};
		// gsl_multimin_function minimization;
		// minimization.n = dim;
		// minimization.f = function_to_minimize;
		// minimization.params = &all_data;
	/*type of minimizer*/
	const gsl_multimin_fminimizer_type *TYPE = gsl_multimin_fminimizer_nmsimplex2;

	/*allocate the minimizer working space*/
	gsl_multimin_fminimizer *working_space = gsl_multimin_fminimizer_alloc(TYPE, dim);
	/*set the minimizer working space*/
	gsl_multimin_fminimizer_set(working_space, &minimization, start, step);

	do{
		iter++;
		status = gsl_multimin_fminimizer_iterate(working_space);
		if (status){
			fprintf(stderr, "gsl_multimin_fminimizer_iterate error: %i", status);
			break;
		}
		double size = gsl_multimin_fminimizer_size (working_space);
      	status = gsl_multimin_test_size (size, 1e-2);

		if (status == GSL_SUCCESS)
			fprintf(stderr, "converged to minimum at:\n");

		fprintf(stderr, "%5zu %10.3e %10.3e %10.3e f() = %7.3f size = %.3f\n", 
			iter,
			gsl_vector_get (working_space->x, 0),
			gsl_vector_get (working_space->x, 1), 
			gsl_vector_get (working_space->x, 2), 
			working_space->fval, size);

	} while (status == GSL_CONTINUE && iter < 1000);

	for(int i = 0; i < n; i++){
		printf("%g %g %g %g\n",t[i],y[i],e[i],decay_function_to_plot(t[i], gsl_multimin_fminimizer_x(working_space)));
	}

	gsl_multimin_fminimizer_free(working_space);
	gsl_vector_free(start);
	gsl_vector_free(step);

	return 0;
}