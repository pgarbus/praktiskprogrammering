#include <stdio.h>
void init(int n, double a[]) {
// void init(int n, double* a) {
	for (int i = 0; i < n; i++) a[i] = 1;
}
int main()
{
	int n=9;
	double* a = malloc(n*sizeof(double));
	//double a[n]; // arrays are equivalent to pointers.
	init(n,a);
	for (int i = 0; i < n; i++) printf("%g ", a[i]);
	printf("accessing out of boundary element in array. We read in junk data., %g\n", a[11]);
	// 	for (int i = 0; i < n; i++) printf("%g\n", *(a+i));
	free(a); 		//to free memory at end of script.
	return 0;
}