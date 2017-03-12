#include <stdio.h>
#include "oscillation.h"

int main(){
	double alpha = 1.0;
	double result = E(alpha);
	fprintf(stderr, "The minimal energy found = %lg\n",result);
	double MAX = 3, step = 0.01;

	for (alpha = step; alpha < MAX; alpha += step)
	{
		printf("%3lg %lg\n", alpha, E(alpha));
	}
	return 0;
}