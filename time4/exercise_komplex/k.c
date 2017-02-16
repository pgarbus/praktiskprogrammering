#include <stdio.h>
#include <math.h>
typedef struct {double re, im;} komplex;

void komplex_set(komplex* z, double x, double y){
	(*z).re = x;
	(*z).im = y;
}
komplex komplex_new(double x, double y){
	komplex result = {.re = x, .im = y};
	return result;
}
komplex komplex_add(komplex* a, komplex* b){
	double x = (*a).re + (*b).re, y = (*a).im + (*b).im;
	komplex result = {.re = x, .im = y};
	return result;
}
komplex komplex_sub(komplex* a, komplex* b){
	double x = (*a).re - (*b).re, y = (*a).im - (*b).im;
	komplex result = komplex_new(x,y);
	return result;
}
komplex komplex_conj(komplex z){
	komplex result = komplex_new(z.re,-z.im);
	return result;
}
void komplex_print(char name[60], komplex z){
	printf("%s = (%g, %g)\n", name, z.re,z.im);
}
void double_print(char name[60], double a){
	printf("%s = %g\n",name, a);
}
/*
int komplex_equal(komplex a, komplex b, double tau, double eps){
	return equal(a.re,b.re,tau,eps) && equal(a.im,b.im,tau,eps);} // your equal function */
double komplex_abs(komplex z){
	double a = fabs(z.re), b = fabs(z.im);
	double result = sqrt(pow(a,2) + pow(b,2));
	return result;
}
int main()
{
	double x = 4; double y = -2;
	komplex z = komplex_new(x,y);			komplex_print("z",z);
	x = 2; y = 3;
	komplex q; komplex_set(&q, x, y); 		komplex_print("q",q);
	komplex z_plus_q = komplex_add(&z,&q); 	komplex_print("z_plus_q", z_plus_q);
	komplex z_minus_q = komplex_sub(&z,&q);	komplex_print("z_minus_q", z_minus_q);
	komplex z_compl_conj = komplex_conj(z); komplex_print("z_compl_conj", z_compl_conj);
	double z_abs = komplex_abs(z);			double_print("z_abs", z_abs);
	return 0;
}
