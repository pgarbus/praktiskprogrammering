#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>

int diff_equation
(double r, const double y[], double dydr[], void * params)
{
	double e = *(double*)params;
	dydr[0]=y[1];
	dydr[1]=2*(-1/r-e)*y[0]; /* -(1/2)u''-(1/r)u = e u */
return GSL_SUCCESS;
}

double Fe(double e, double r){
	assert(e<0);
	assert(r>=0);
	const double rmin=1e-3;
	if(r<rmin)return r-r*r;

	gsl_odeiv2_system sys;
	sys.function = diff_equation;
	sys.jacobian = NULL;
	sys.dimension = 2;
	sys.params = (void*)&e;

	double acc=1e-6,eps=1e-6,hstart=0.01;
	gsl_odeiv2_driver *driver=gsl_odeiv2_driver_alloc_y_new
		(&sys,gsl_odeiv2_step_rkf45,hstart,acc,eps);

	double t=rmin,y[2]={t-t*t,1-2*t};
	gsl_odeiv2_driver_apply(driver,&t,r,y);

	gsl_odeiv2_driver_free(driver);
	return y[0];
}