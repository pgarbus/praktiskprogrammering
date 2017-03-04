#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_vector.h>

void m_print(gsl_matrix* matrix, int dim, char comment[70]){
	fprintf(stderr,"%s\n", comment);
	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j)
		 {
		  	fprintf(stderr,"%5.1g\t",gsl_matrix_get(matrix,i,j));
		 }
		 fprintf(stderr,"\n");
	}
	fprintf(stderr,"\n");
}

void v_print(gsl_vector* vector, int dim, char comment[70]){
	fprintf(stderr,"%s\n", comment);
	for (int i = 0; i < dim; ++i)
	{
	  	fprintf(stderr,"%10.7g",gsl_vector_get(vector,i));
		fprintf(stderr,"\n");
	}
	fprintf(stderr,"\n");
}