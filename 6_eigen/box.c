#include <stdio.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_linalg.h>
#include <math.h>
#include "helper.h"

int box(void)
{
	printf("\n\nWELCOME TO THE BOX EXERCISE!\n");
	printf("Build the Hamiltonian matrix H′ as a gsl_matrix structure\n");
	int n=20;
	double s=1.0/(n+1);
	gsl_matrix* H = gsl_matrix_calloc(n,n);
	for(int i=0;i<n-1;i++){
	  gsl_matrix_set(H,i,i,-2);
	  gsl_matrix_set(H,i,i+1,1);
	  gsl_matrix_set(H,i+1,i,1);
	  }
	gsl_matrix_set(H,n-1,n-1,-2);
	gsl_matrix_scale(H,-1/s/s);

	m_print(H,n,"matrix H at the very beginning of rutine. diaogonal and\
	adjacent entries are supposed to be -2 and 1. but they are not?");
	
	printf("Diagonalize the matrix using GSL subroutines for diagonalization \
of real symmetric matrices.\n");
	gsl_eigen_symmv_workspace* w =  gsl_eigen_symmv_alloc (n);
	gsl_vector* eval = gsl_vector_alloc(n);
	gsl_matrix* evec = gsl_matrix_calloc(n,n);
	gsl_eigen_symmv(H,eval,evec,w);

	m_print(evec,n,"matrix evec.");
	v_print(eval,n,"vector eval.");
	
	printf("Sort the eigenvalues and eigenvectors\n");
	gsl_eigen_symmv_sort(eval,evec,GSL_EIGEN_SORT_VAL_ASC);
	m_print(evec,n,"matrix evec after sorting.");
	v_print(eval,n,"vector eval after sorting");

	printf("Check that your energies are correct\n");
	fprintf (stderr, "%2s %12s %12s\n", "i", "exact", "calculated");
	for (int k=0; k < n/3; k++){
	    double exact = pow(M_PI,2)*(k+1)*(k+1);
	    double calculated = gsl_vector_get(eval,k);
	    fprintf (stderr, "%2i %12.7g %12.7g\n", k, exact, calculated);
	}
	printf("\n");
	
	printf("Plot the several lowest eigenfunctions (and compare with the analytical result).\n"); 
	for(int k=0;k<3;k++){
	  printf("%12.7g %12.7g\n",0.0,0.0);
	  for(int i=0;i<n;i++) printf("%12.7g %12.7g\n",(i+1.0)/(n+1),gsl_matrix_get(evec,i,k));
	  printf("%12.7g %12.7g\n",1.0,0.0);
	  printf("\n\n");
	  }
	// You may try to investigate how the accuracy changes with the number of grid points.
	m_print(H,n,"GSL MAtrix at end of rutine.");
	
	gsl_matrix_free(H);
	gsl_matrix_free(evec);
	gsl_vector_free(eval);
	return 0;
}