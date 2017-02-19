#include <stdio.h>
#include <stdlib.h> // 
#include <math.h>
#define PI 3.1415927
#define MAX(a,b) (a)<(b)?(a):(b) // use paranthesis for safety.
#define RND (double)rand()/RAND_MAX

// #define TRACE(args...) fprintf(stderr, args);
#define TRACE(args...)

int main()
{
	TRACE("max(0,1) = %g\n",MAX(0.0,1.0));
	double x,a=0,b=10,dx=0.5;
	for (x=a;x<=b;x+=dx){
		double y=sin(x)+(RND-0.5)/2;
		double e=RND/2;
		printf("%g \t %g \t %g\n",x,y,e);
	}
	return 0;
}

/*
in gnuplot:
set terminal pdf

make main
./main 2> junk //to have error output
./main > junk //for standard output

website to upload homework:
http://users-phys.au.dk/fedorov/pmwiki-2.2.83/pmwiki.php
http://owww.phys.au.dk/~fedorov/pmwiki-2.2.83/pmwiki.php?n=Main.Homeworks
*/