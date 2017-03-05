#include <stdio.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>

int differential_function(double t, const double y[], double f[], void *params){
	(void) t; /*avoid warning about unused variable. 
	is this parameter needed for stepper function?*/
	/*we need to implement this ordinary differential equation: y'(x) = y(x)*(1-y(x))*/
	(void) params;
	f[0] = y[0]*(1/y[0]); 
	return GSL_SUCCESS;
}
	/*we don't need to bother about Jacobian matrix - not yet*/

int main()
{
	{ /*PelleGarbus*/
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
		double y[1]={0.5}, t = 0.0;
		int steps = 10; 
		double x_min = 0, x_max = 3, step_size = (x_max - x_min)/(double)steps;
		for (double x = x_min; x < x_max; x+=step_size)
		{
			int status = gsl_odeiv2_driver_apply(d, &t, x, y);
			if (status != GSL_SUCCESS){
				printf("Error, returned status = %d\n", status);
				break;
			}
			printf("x = %8.5g\ty = %8.5g\n", x,*y);
		}
		gsl_odeiv2_driver_free(d);
	}
	return 0;
}