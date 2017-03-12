#include <stdio.h>
#include <gsl/gsl_odeiv2.h>
#include <gsl/gsl_errno.h>
#include <math.h>

int differential_function(double t, const double y[], double f[], void *params){
	(void) t; /*avoid warning about unused variable. 
	is this parameter needed for stepper function?*/
	/*we need to implement this ordinary differential equation: y'(x) = y(x)*(1-y(x))*/
	(void) params;
	f[0] = y[0]*(1/y[0]); /*y'(x) = y(x)*(1-y(x))*/
	return GSL_SUCCESS;
}
	/*we don't need to bother about Jacobian matrix - not at all*/
int orbit_function(double phi, const double y[], double f[], void *params){
	(void) phi;
	double epsilon = *(double *) params;
	/*
	y0' = y1
	y1' = 1-y0+ε*y0*y0 
	*/
	f[0] = y[1];
	f[1] = 1-y[0]+epsilon*y[0]*y[0];
	return GSL_SUCCESS;
}
int main()
{
	{ /*PelleGarbus*/
		printf("EXERCISE: ORDINARY DIFFERENTIAL SYSTEM\n");
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

	{/*PelleGarbus Orbit*/
		printf("EXERCISE: ORBITING PLANET\n");
		double input;
		double params[3];
		for(int i = 0; i < 3; i++){
			scanf("%lg",&input);
			params[i] = input;
		}
		size_t dim = 2;
		void* jacobian = NULL;
		double* epsilon = &params[0];/*need to be a list or similar with 0, 0, 0.1*/
		gsl_odeiv2_system orbit_system = {orbit_function, jacobian, dim, &epsilon};
		double hstart = 1e-1, epsabs = 1e-6, epsrel = 0;
		gsl_odeiv2_driver* orbit_driver = gsl_odeiv2_driver_alloc_y_new(
			&orbit_system,
			gsl_odeiv2_step_rk8pd,
			hstart,
			epsabs,
			epsrel
			);
		double modified_t = 0.0; /*ths parameter will be constantly 
		changed to drive the system from t_initial to t_final*/
		double u0 = params[1], u1 = params[2]; /*extract information from a matrix and iterate.*/
		double u[2] = {u0, u1}; /*will contain the values obtained 
		from the driver_applied inside the for-loop for each phi-step.*/
		double phi_min = 0, phi_max = 39.5 * M_PI, delta_phi = 0.5; /*blindly copied from Fedorov*/
		printf("%10s %10s %10s\n", "phi", "y0", "y1");
		for (double phi = phi_min; phi < phi_max; phi += delta_phi){
			int status = gsl_odeiv2_driver_apply(orbit_driver, &modified_t,phi,u);
			if (status != GSL_SUCCESS){
				fprintf(stderr, "Error, returned status = %d\n", status);
				break;
			}
			// if(fmod(phi,5.0) == 0.0) printf("%10.7g %10.7g %10.7g\n", phi,u[0],u[1]);
			printf("%10.7g %10.7g %10.7g\n", phi,u[0],u[1]);
		}
		gsl_odeiv2_driver_free(orbit_driver);
	}
	return 0;
}