#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include<stdio.h>
#include<assert.h>
#define STEPPER gsl_odeiv2_step_rkf45
#define ABSERR 1e-6
#define RELERR 1e-6
#define STARTSTEP 1e-6

int hydrogen_diff(double radius, const double y[], double dydr[], void* params){
	double energy = *(double*)params;
	double f = y[0];
	double df_dr = y[1];

	dydr[0] = df_dr;
	dydr[1] = -2*(1/radius+energy) * f; 
	/* s-wave radial schrodinger Eq
		-(1/2)f'' -(1/r)f = εf  ==> f'' = -2(ε+ 1/r)*f */
return GSL_SUCCESS;
}

double auxilian_Me(double energy, double r){
	assert(r>=0);
	const double rmin = 1e-3;
	if(r<rmin) return r-r*r;

	gsl_odeiv2_system system;
	system.function = hydrogen_diff;
	system.jacobian = NULL;
	system.dimension = 2;
	system.params = (void*)&energy;

	gsl_odeiv2_driver* driver = 
		gsl_odeiv2_driver_alloc_y_new(&system, STEPPER, STARTSTEP, ABSERR, RELERR);

	double r_start=rmin, y[] = {r_start-r_start*r_start, 1-2*r_start}; 
		/*contains the initial vector [position, velocity]. 
		f(0) = r - r*r and the derivative  of f(0) */
	int status = gsl_odeiv2_driver_apply(driver, &r_start, r, y); 
		/*drives the system from r_start to r*/
	if (status != GSL_SUCCESS) fprintf (stderr,"Fe: odeiv2 error: %d\n", status);

	gsl_odeiv2_driver_free (driver);
	return y[0];
}