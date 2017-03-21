#include<math.h>
#include<assert.h>
#include<gsl/gsl_integration.h>
#include<gsl/gsl_errno.h>

double fhf(double r, void* params){
	double *p=(double*)params;
	double s=p[0];
	double a=p[1];
	double f=pow(r,s)*exp(-a*r);
	double kf=-1./2*(
		s*(s-1)*pow(r,s-2)
		-2*s*pow(r,s-1)*a
		+a*a*pow(r,s)
		)*exp(-a*r);
	double vf = (-1/r)*f;
	return f*(kf+vf);
}

double f1f(double r, void* params){
	double *p=(double*)params;
	double s=p[0];
	double a=p[1];
	double f=pow(r,s)*exp(-a*r);
	return f*f;
}

double E(double s, double a){
	assert(s>0 && a>0);
	double p[2] = {a,s};

	gsl_function Fh;
	gsl_function F1;
	Fh.function = fhf;
	F1.function = f1f;
	Fh.params = (void*)p;
	F1.params = (void*)p;

	int limit = 100;
	double r0=0,acc=1e-5,eps=1e-5,resultH,result1,err;
	gsl_integration_workspace * workspace =
		gsl_integration_workspace_alloc(limit);

int statusH;
int status1;
statusH=gsl_integration_qagiu(&Fh,r0,acc,eps,limit,workspace,&resultH,&err);
status1=gsl_integration_qagiu(&F1,r0,acc,eps,limit,workspace,&result1,&err);

gsl_integration_workspace_free(workspace);
if(statusH!=GSL_SUCCESS) return NAN;
if(status1!=GSL_SUCCESS) return NAN;
else return resultH/result1;
}