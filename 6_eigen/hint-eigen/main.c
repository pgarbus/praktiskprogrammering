#include<stdio.h>
#include<gsl/gsl_vector.h>
#include<gsl/gsl_matrix.h>
#include<gsl/gsl_eigen.h>

const double pi = 3.14159265358979323844;
double oscillator(double x)
{
	return 0.5 * x * x;
}

double coulomb(double x)
{
	return -1 / x;
}

int main(void)
{
	int npoints = 250;
//      double from_point=-7, to_point=7;
	double from_point = 0, to_point = 37;
	double step = (to_point - from_point) / (npoints + 1);

	gsl_matrix *H = gsl_matrix_calloc(npoints, npoints);
	for (int i = 0; i < npoints - 1; i++) {
		gsl_matrix_set(H, i, i, -2);
		gsl_matrix_set(H, i, i + 1, 1);
		gsl_matrix_set(H, i + 1, i, 1);
	}
	gsl_matrix_set(H, npoints - 1, npoints - 1, -2);
	gsl_matrix_scale(H, -0.5 / step / step);

	gsl_vector *xvec = gsl_vector_alloc(npoints);
	for (int i = 0; i < npoints; i++)
		gsl_vector_set(xvec, i, from_point + (i + 1) * step);

	for (int i = 0; i < npoints; i++) {	/* add potential energy */
		double Hii = gsl_matrix_get(H, i, i);
		double xi = gsl_vector_get(xvec, i);
//              double Vxi = oscillator(xi);
		double Vxi = coulomb(xi);
		gsl_matrix_set(H, i, i, Hii + Vxi);
	}

	gsl_eigen_symmv_workspace *w = gsl_eigen_symmv_alloc(npoints);
	gsl_vector *eval = gsl_vector_alloc(npoints);
	gsl_matrix *evec = gsl_matrix_calloc(npoints, npoints);
	gsl_eigen_symmv(H, eval, evec, w);
	gsl_eigen_symmv_sort(eval, evec, GSL_EIGEN_SORT_VAL_ASC);

	fprintf(stderr, "# energies\n");
	fprintf(stderr, "n\tcalculated\texact\n");
	for (int n = 0; n < 9; n++) {	// print first few eigenvalues
		double calculated = gsl_vector_get(eval, n);
//              double exact = n + 1 / 2.;
		double exact = -1 / 2. * 1. / (n + 1) / (n + 1);
		fprintf(stderr, "%3i\t%9.3f\t%9.3f\n", n + 1, calculated,
			exact);
	}

	printf("x u0 u1 u2\n");
	printf("%f %f %f %f\n", from_point, 0., 0., 0.);
	for (int i = 0; i < npoints; i++) {
		double x = gsl_vector_get(xvec, i);
		double u0 = gsl_matrix_get(evec, i, 0);
		double u1 = gsl_matrix_get(evec, i, 1);
		double u2 = gsl_matrix_get(evec, i, 2);
		printf("%f %f %f %f\n", x, u0, u1, u2);
	}
	printf("%f %f %f %f\n", to_point, 0., 0., 0.);

	gsl_matrix_free(H);
	gsl_matrix_free(evec);
	gsl_vector_free(eval);
	gsl_vector_free(xvec);
	gsl_eigen_symmv_free(w);

	return 0;
}