#include <stdio.h>
#include <gsl/gsl_eigen.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_linalg.h>

// This function needs to be declared in header file!!
void m_print(gsl_matrix* matrix, int dim, char[70] comment[]){
	printf("%s\n", comment);
	for (int i = 0; i < dim; ++i)
	{
		for (int j = 0; j < dim; ++j)
		 {
		  	printf("%5.3g\t",gsl_matrix_get(matrix,i,j));
		 }
		 printf("\n");
	}
	printf("\n");
}

int main(void)
{
	//  Build the Hamiltonian matrix H′ as a gsl_matrix structure
	printf("hello box!\n");
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

	// Diagonalize the matrix using GSL subroutines for diagonalization of real symmetric matrices.

	gsl_eigen_symmv_workspace* w =  gsl_eigen_symmv_alloc (n);
	gsl_vector* eval = gsl_vector_alloc(n);
	gsl_matrix* evec = gsl_matrix_calloc(n,n);
	gsl_eigen_symmv(H,eval,evec,w);

	// Sort the eigenvalues and eigenvectors

	//  Check that your energies are correct

	// Plot the several lowest eigenfunctions (and compare with the analytical result). 

	// You may try to investigate how the accuracy changes with the number of grid points.


	// printing out results
	m_print(H,n,"my name is Pelle");
	return 0;
}