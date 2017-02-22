#include <stdio.h>
void init_old(double u){
	u=1;

}
void init(double* u){
	*u=1;
}
int main(int argc, char const *argv[])
{
	double x = 1.23;
	init_old(x);
	double* p = &x;
	printf("from init_old: *p=%g\n", *p);
	init(&x);
	/*print out the imaginary space occupied by x*/
	printf("&x=%i\n",(int)&x); // we cast double pointer to int output.
	// &x: kernel creates an image of location
	//reference operator
	printf("from init: *p=%g\n", *p);

	return 0;
}
