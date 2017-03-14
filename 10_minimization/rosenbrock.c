#include <stdio.h>
#include <gsl/gsl_multimin.h>
#include <math.h>

double 	rosenbrock (const gsl_vector *start, void *params){
	double *p = (double *)params;
	double a = p[0], b = p[1];

	double x = gsl_vector_get(start, 0);
	double y = gsl_vector_get(start, 1);
	
	return pow((a-x),2) + b*pow((y-x*x),2);
}

// 	/* The gradient of f, df = (df/dx, df/dy). */
// void my_df (const gsl_vector *start, void *params, gsl_vector *df){
// 	double x, y;
// 	double *p = (double *)params;

// 	x = gsl_vector_get(start, 0);
// 	y = gsl_vector_get(start, 1);

// 	gsl_vector_set(df, 0, -2.0 * (p[0] - x) - x * 2.0 * p[2] * (y-x*x));
// 	gsl_vector_set(df, 1, 2.0 * p[1] * (y - x*x));
// }

// 	/* Compute both f and df together. */
// void my_fdf (const gsl_vector *x, void *params, double *f, gsl_vector *df){
//   *f = rosenbrock(x, params); 
//   my_df(x, params, df);
// }

int main(void)
{
	/* parameters to rosebrock function */
	double par[2] = {1.0, 100.0};
	/*dimension of parameter space*/
	size_t dim = 2;
	/*initialize starting point vector*/
	gsl_vector *start;
	start = gsl_vector_alloc(2);
	/*starting points*/
	gsl_vector_set(start, 0, -1.5);
	gsl_vector_set(start, 1, 150.5);
	/*initial stepping size*/
	gsl_vector *step = gsl_vector_alloc(2);
	gsl_vector_set_all(step,1.0);
	/*initilize function to minimize*/
	gsl_multimin_function mini_rosen;
	mini_rosen.n = dim;
	mini_rosen.f = rosenbrock;
	mini_rosen.params = par;
	/*type of minimizer*/
	const gsl_multimin_fminimizer_type *TYPE = gsl_multimin_fminimizer_nmsimplex2;

	/*allocate the minimizer working space*/
	gsl_multimin_fminimizer *working_space = gsl_multimin_fminimizer_alloc(TYPE, dim);
	/*set the minimizer working space*/
	gsl_multimin_fminimizer_set(working_space, &mini_rosen, start, step);

	/*returned status from gsl_fminimizer.*/
	int status;
	/*iterator book keeper*/
	size_t iter = 0;
	/*parameter names for rosenbrok.out*/
	fprintf(stdout, "%s %s %s %s %s\n", "iter","x","y","fval","size");
	do{
		iter++;
		status = gsl_multimin_fminimizer_iterate(working_space);
		if (status)
			break;
		double size = gsl_multimin_fminimizer_size (working_space);
      	status = gsl_multimin_test_size (size, 1e-7);

		if (status == GSL_SUCCESS)
			fprintf(stderr,"converged to minimum at:\n");

		fprintf(stdout,"%5zu %10.3e %10.3e %7.3e %.3e\n", 
			iter,
			gsl_vector_get (working_space->x, 0), 
			gsl_vector_get (working_space->x, 1), 
			working_space->fval, 
			size);

		fprintf(stderr,"%5zu %10.3e %10.3e f() = %7.3f size = %.3f\n", 
			iter,
			gsl_vector_get (working_space->x, 0), 
			gsl_vector_get (working_space->x, 1), 
			working_space->fval, 
			size);
	} while (status == GSL_CONTINUE && iter < 10000);

	gsl_multimin_fminimizer_free(working_space);
	gsl_vector_free(start);
	gsl_vector_free(step);

	return 0;
}