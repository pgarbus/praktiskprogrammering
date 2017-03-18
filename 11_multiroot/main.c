#include <stdio.h>
#include <gsl/gsl_multiroots.h>
#include <math.h>
#include <assert.h>
#include <gsl/gsl_errno.h>


// For the first exercise!
struct rparams {double a; double b;};

int rosenbrock_f(const gsl_vector * arguments, void *params, gsl_vector * results){
	double a = ((struct rparams *) params)->a;
	double b = ((struct rparams *) params)->b;

	const double x = gsl_vector_get(arguments, 0);
	const double y = gsl_vector_get(arguments, 1);

	const double df_dx = a * (-2*(1-x)) + b*(-4*x*(y-x*x));
	const double df_dy = 2*b * (y - x * x);

	/* this should be a function that returns the differential quitients for x and y,
		that is x' and y' called xprime and yprime.
	*/

	gsl_vector_set(results, 0, df_dx);
	gsl_vector_set(results, 1, df_dy);

	return GSL_SUCCESS;
}

void print_state(size_t iter, gsl_multiroot_fsolver * s){
	printf("%3zu = iter %7.3f = x %7.3f = y"
		"%10.1e = df/dx %10.1e = df/dy\n",
		iter,
		gsl_vector_get(s->x, 0), 
		gsl_vector_get(s->x, 1),
		gsl_vector_get(s->f, 0), 
		gsl_vector_get(s->f, 1));
}

void print_state2(int iter, gsl_multiroot_fsolver * s){
	printf("%3i = iter %7.3f = Energy"
		"%10.1e = radial wave func\n",
		iter,
		gsl_vector_get(s->x, 0), 
		gsl_vector_get(s->f, 0));
}

// For the second exercise!
double auxilian_Me(double energy, double r); /*REMEMBER TO LINK DEPENDENCY IN MAKEFILE!*/

int master(const gsl_vector *x, void *params, gsl_vector *f){
	double energy=gsl_vector_get(x,0);
	assert(energy<0);
	double rmax = *(double*)params;
	double fval = auxilian_Me(energy,rmax);
	gsl_vector_set(f,0,fval);
	return GSL_SUCCESS;
}

// the main function
int main(void)
{
	// if (0)
	{ /*exercise find root of rosenbrock gradient*/
		printf("Hello world, exercise 1\n");

		const gsl_multiroot_fsolver_type *TYPE;
		gsl_multiroot_fsolver *multiroot_solver;

		int status;
		size_t iter = 0;

		const size_t dimension = 2;
		struct rparams p = {1.0, 100.0};
		gsl_multiroot_function f = {.f=&rosenbrock_f, .n=dimension, .params=&p};

		double x_init[2] = {-0.2, 5.2};
		gsl_vector *arguments = gsl_vector_alloc(dimension);

		gsl_vector_set(arguments, 0, x_init[0]);
		gsl_vector_set(arguments, 1, x_init[1]);

		TYPE = gsl_multiroot_fsolver_hybrids;
		multiroot_solver = gsl_multiroot_fsolver_alloc(TYPE, (int) dimension);
		gsl_multiroot_fsolver_set(multiroot_solver, &f, arguments);

		print_state(iter, multiroot_solver);

		do{
			iter++;
			status = gsl_multiroot_fsolver_iterate(multiroot_solver);

			print_state(iter, multiroot_solver);

			if (status)   /* check if solver is stuck */
				break;

			status = gsl_multiroot_test_residual(multiroot_solver->f, 1e-7);
		} while (status == GSL_CONTINUE && iter < 1000);

		printf ("status = %s\n", gsl_strerror(status));

		gsl_multiroot_fsolver_free(multiroot_solver);
		gsl_vector_free(arguments);
		}
	
	// else
	{ /*exercise find solution to schroedinger equation for the hydrogen atom*/
		

		printf("Hello world, exercise 2\n");
		const gsl_multiroot_fsolver_type *TYPE = gsl_multiroot_fsolver_hybrids;
		gsl_multiroot_fsolver *solver;

		// int status;
		// int iter=0;
		const double rmax = 2
		;

		const size_t dimension = 1;
		gsl_multiroot_function f = {.f=master, .n=dimension, .params= (void*) &rmax};

		double energy = -100.5;
		gsl_vector *arguments = gsl_vector_alloc(dimension);
		// gsl_vector *arguments = gsl_vector_alloc(dimension);
		gsl_vector_set(arguments, 0, energy);

		// Setting the solver
		solver = gsl_multiroot_fsolver_alloc(TYPE, dimension);
		gsl_multiroot_fsolver_set(solver, &f, arguments);


		int status, iter = 0;
		do{
			iter++;
			status = gsl_multiroot_fsolver_iterate(solver);

			print_state2(iter, solver);

			if (status)   /* check if solver is stuck */
				break;

			status = gsl_multiroot_test_residual(solver->f, 1e-7);
		} while (status == GSL_CONTINUE && iter < 1000);

		FILE *DATA = fopen("data.out","w");
		int resolution = 50;
		double final_energy = gsl_vector_get(solver->x,0);
		for (int i = 1; i<resolution;i++){
			double r = rmax * i / resolution;
			double psi_2 = auxilian_Me(final_energy,r);
			fprintf(DATA, "%g %g\n",r,psi_2);
		}
		fclose(DATA);


		printf("Success: Root found\n%4i = iter %7.3g = energy %7.3g = psi_2\n",
			iter,gsl_vector_get(solver->x,0),gsl_vector_get(solver->f,0));

		gsl_vector_free(arguments);
		gsl_multiroot_fsolver_free(solver);
	}
	/*
	Find the lowest root, ε0, of the equation M(ε) = 0 for, say, rmax=8. Plot the 
	resulting function and compare with the exact result (ε0=-1/2, f0(r)=re-r – check this). 
	*/

	return 0;
}