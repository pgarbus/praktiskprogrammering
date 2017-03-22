#include <stdio.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>
#include <math.h>
#include <float.h>

#define START -M_PI
#define END M_PI
#define STEPS 500.0

int differential_function(double t, const double y[], double f[], void *params){
	(void) t; /*avoid warning about unused variable. 
	is this parameter needed for stepper function?*/
	/*we need to implement this ordinary differential equation: y'(x) = y(x)*(1-y(x))*/
	(void) params;
	// f[0] = y[0]*(1/y[0]); /*y'(x) = y(x)*(1-y(x))*/
	f[0] = 1 + y[0]*y[0];  // y' = 1 + y**2, 
	return GSL_SUCCESS;
}

int main(void)
{

	{
		fprintf(stderr, "Answer question 7 from lecture 1.\n");
		fprintf(stderr, "What are the built-in data types for numbers in the C-language?\n");
	}
	{
		// fprintf(stderr, "Answer practical assignment 34 or 13\n");

		{ /*Ordinary differential system: tangential function*/
			fprintf(stderr, "EXAM: ORDINARY DIFFERENTIAL SYSTEM\n");
			size_t dim = 1;
			void* jacobian = NULL; /*should be pointer*/
			void* params = NULL; /*should be pointer*/
			gsl_odeiv2_system ode = {differential_function, jacobian, dim, params};
			double hstart = 1e-1, epsabs = 1e-6, epsrel = 0; 
			gsl_odeiv2_driver* d = gsl_odeiv2_driver_alloc_y_new(
				&ode, 
				gsl_odeiv2_step_rk8pd, 
				hstart, /*starting step size*/ 
				epsabs, /*absolute error*/
				epsrel /*relative error*/
				);
			/*from x=0 to x=3 with the initial condition y(0)=0.5. 
			Compare with the analytic result (should be the logistic function). */
			double y[1]={0.0}, t = 0.0;
			int steps = 500; 
			double neg_x[steps], neg_y[steps];
			double pos_x[steps], pos_y[steps];
			double x_min = 0, x_max = M_PI/2 - FLT_EPSILON, step_size = 
				(x_max - x_min)/(double)steps;
			int i = 0;
			for (double x = x_min; x < x_max; x+= step_size)
			{
				int status = gsl_odeiv2_driver_apply(d, &t, x, y);
				if (status != GSL_SUCCESS){
					fprintf(stderr, "Error, returned status = %d\n", status);
					break;
				}
				pos_x[i] = x;
				pos_y[i] = *y;
				neg_x[steps-i] = -x;
				neg_y[steps-i] = -*y;
				++i;
			}
			FILE *OUT = fopen("odeiv.out","w");
			for (int i = 0; i < steps; ++i)	
				fprintf(OUT, "%8.5g %8.5g\n", neg_x[i],neg_y[i]);
			for (int i = 0; i < steps; ++i)	
				fprintf(OUT, "%8.5g %8.5g\n", pos_x[i],pos_y[i]);
			fclose(OUT);
			gsl_odeiv2_driver_free(d);
		}
		{ /*math.h tangential function*/
			const double STEP = (END-START)/STEPS;
			fprintf(stderr, "math.h %g %g %g\n", END, START, STEP);
			FILE *OUT = fopen("math_h_tan.out","w");
			for(double i = START; i < END; i+=STEP)
			{
				fprintf(OUT, "%g %g\n", i, tan(i));
			}fclose(OUT);
			}
	}
	return 0;
}


		/*
		Elliptic Integral of First Kind.
		Implement the ’elliptic intergal of first kind’ function
		F(φ,k) using the integral representation
		*/