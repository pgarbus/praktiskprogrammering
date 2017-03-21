#include "nvector.h"
#include "stdio.h"
#include "stdlib.h"
#include <math.h>

double* foo(){static double a[]={0,0,0}; return a; }
double* bar(){double* b=(double*)malloc(3*sizeof(double)); return b;}

int main()
{
	{
		printf("\nQUESTION 6\n");
		printf("If static in foo() is removed, the pointer to array vanishes.\n");
		double* a=foo(); a[2]=1;
		double* b=foo(); b[2]=2;
		printf("a[2] = %g\n",a[2]);
	}
	{
		printf("QUESTION 7\n");
		printf("Malloc seems to already invoke static.\n"
			"note malloc is void* wich takes in size_t types.\n"
			"in function bar() the malloc is cast to double*");
		double* b=bar(); b[2]=1;
		double* c=bar(); c[2]=2;
		printf("b[2] = %g\n",b[2]);
		free(b);b=NULL;
		free(c);c=NULL;
	}
	{
		printf("QUESTION 10\n");
		double (*f)(double) = sin;
		double (*g)(double) = &sin;
		printf("double (*f)(double) = sin; f(1) = %g \n"
			"double (*g)(double) = &sin; g(1) = %g\n",f(1), g(1));
		printf("Appereantly both notations are valid!\n");
		double y = f(1);
		double z = (*f)(1);
		printf("f(1) = %g, (*f)(1) = %g\n", y,z);
		printf("someone made sure these two calls behave the same...\n");
	}
	// Main FUNC is appearently not needed...
	printf("\nEXERCISE.\n");
	nvector* v = nvector_alloc(3);
	nvector* w = nvector_alloc(3);
	nvector_print("printing v before setting values = ",v);
	// free(v);
	// nvector_print("printing v = ",v);
	nvector_set(v,0,3);
	nvector_set(v,1,4);
	nvector_set(v,2,8);
	nvector_set(w,0,14);
	nvector_set(w,1,13);
	nvector_set(w,2,11);
	
	nvector_print("printing v after setting values = ",v);
	nvector_print("printing w after setting values = ",w);
	int index = 1;
	printf("(*v).data[%i] = %g\n", index, nvector_get(v,index));
	double dotproduct = nvector_dot_product(v,w);
	printf("dot product v and w = %g\n", dotproduct);
	int is_equal = nvector_equal(v,w);
	printf("vector v and w are equal (1) or not (0): %i\n",is_equal);

	nvector_print("printing v before adding w = ",v);
	nvector_add(v,w);
	nvector_print("printing v after adding w = ",v);
	
	nvector_sub(v,w);
	nvector_print("printing v after substracting w = ",v);
	
	nvector_scale(v,5);
	nvector_print("printing v after scaling with 5 = ",v);
	

	nvector_set_zero(v);
	nvector_set_zero(w);
	nvector_print("printing v after zeroing values = ",v);
	nvector_print("printing w after zeroing values = ",w);
	is_equal = nvector_equal(v,w);
	printf("vector v and w are equal (1) or not (0): %i\n",is_equal);

	return 0;
}