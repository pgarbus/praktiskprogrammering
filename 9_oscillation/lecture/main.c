#define ALG gsl_multimin_fminimizer_nmsimplex2
#include<stdio.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_multimin.h>

double E(double s,double a);

double master (const gsl_vector * x, void * params){
	double s=gsl_vector_get(x,0);
	double a=gsl_vector_get(x,1);
	return E(s,a);
}

int main(){
	size_t dim=2;
	gsl_multimin_function F;
	F.f=master;
	F.n=dim;
	F.params=NULL;

gsl_multimin_fminimizer * state =
gsl_multimin_fminimizer_alloc (ALG,dim);
gsl_vector *start = gsl_vector_alloc(dim);
gsl_vector *step = gsl_vector_alloc(dim);
gsl_vector_set(start,0,1.5); /* s_start */
gsl_vector_set(start,1,1.5); /* a_start */
gsl_vector_set_all(step,0.05);
gsl_multimin_fminimizer_set (state, &F, start, step);

int iter=0,status;
double acc=0.001;
do{
	iter++;
	int flag = gsl_multimin_fminimizer_iterate (state);
	if(flag!=0)break;
	status = gsl_multimin_test_size (state->size, acc);
	if (status == GSL_SUCCESS) fprintf (stderr,"converged\n");
	fprintf(stderr,
		"iter=%2i, s= %8f, a= %8f, E= %8g, size= %8g\n",
		iter,
		gsl_vector_get(state->x,0),
		gsl_vector_get(state->x,1),
		state->fval,
		state->size);
}while(status == GSL_CONTINUE && iter < 99);
	

gsl_vector_free(start);
gsl_vector_free(step);
gsl_multimin_fminimizer_free(state);
return 0;
}