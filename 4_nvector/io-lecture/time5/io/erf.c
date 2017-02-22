/*
ERROR CHANNEL
./erf 1< out.txt 2> out2.txt
PIPING:
echo 1.23 | ./erf
UNCOMMENTE WHILE and type in cmd:
echo 1.45 | ./erf 2.45
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char** argv){
	// FILE* mystream = fopen("out.txt", "w"); 
	// filename hardcoded in script. should be in makefile
	double x;
	if(argc>1) x = atof(argv[1]);
	printf("Command line  argument = %g\n", x);
	fprintf(stdout, "Hello\n");
	fprintf(stderr, "Error\n");
	while(scanf("%lg",&x) != EOF){
		printf("x = %g\n", x);
	}
	// scanf("%lg",&x);
	// printf("x = %g\n", x);
	return 0;
}