#include<stdio.h>
#include<math.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>

int sine_diff_equation
(double t, const double y[], double dydt[], void * params)
{
	dydt[0]=y[1];
	dydt[1]=-y[0];
return GSL_SUCCESS;
}

double sine_function(double x){
	gsl_odeiv2_system sys;
	sys.function = sine_diff_equation;
	sys.jacobian = NULL;
	sys.dimension = 2;
	sys.params = NULL;

	double acc=1e-6,eps=1e-6,hstart=copysign(0.1,x);
	gsl_odeiv2_driver *driver=gsl_odeiv2_driver_alloc_y_new
		(&sys,gsl_odeiv2_step_rkf45,hstart,acc,eps);

	double t=0,y[2]={0,1};
	gsl_odeiv2_driver_apply(driver,&t,x,y);

	gsl_odeiv2_driver_free(driver);
	return y[0];
}

int main(){
	double a=-5,b=5,dx=0.2;
	for(double x=a;x<=b;x+=dx)printf("%g %g %g\n",x,sine_function(x),sin(x));
return 0;
}
	