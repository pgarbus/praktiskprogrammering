#include<stdio.h>
#include<math.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_odeiv2.h>
#include<gsl/gsl_errno.h>
#include<gsl/gsl_multiroots.h>
#define ALG gsl_multiroot_fsolver_hybrids

double Fe(double a, double r);

int master(const gsl_vector * x, void * params, gsl_vector * f){
	double e = gsl_vector_get(x,0);
	double rmax = *(double*)params;
	gsl_vector_set(f,0,Fe(e,rmax));
	return GSL_SUCCESS;
}

int main(){
const int dim = 1;
const double rmax = 8;
gsl_multiroot_function M;
M.f = master;
M.n = dim;
M.params = (void*)&rmax;

gsl_multiroot_fsolver *s = gsl_multiroot_fsolver_alloc (ALG, dim);
gsl_vector * x = gsl_vector_alloc(dim);
gsl_vector_set(x,0,-.8);
gsl_multiroot_fsolver_set (s, &M, x);

int iter=0,status;
const double acc=1e-3;
do{
	iter++;
	int flag=gsl_multiroot_fsolver_iterate(s);
	if(flag!=0)break;
	status = gsl_multiroot_test_residual (s->f, acc);
	fprintf(stderr
		,"iter= %2i, E= %8f, Fe(%8g)= %g\n"
		,iter
		,gsl_vector_get(s->x,0)
		,rmax
		,gsl_vector_get(s->f,0)
		);
}while(status == GSL_CONTINUE && iter<99);
	
gsl_vector_free(x);
gsl_multiroot_fsolver_free (s);
return 0;
}