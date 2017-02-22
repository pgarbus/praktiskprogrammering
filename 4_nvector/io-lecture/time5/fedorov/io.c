#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void print_f_of_1(double (*f)(double));

int main(int argc, char** argv){

        double (*f[3])(double) = {sin,cos,tan};
        for(int i=0;i<3;i++)printf("f[%i](1) = %g ",i,f[i](1));

        struct funs {double (*a)(double); double(*b)(double);};
        struct funs F = {.a=sin,.b=cos};
        printf("\nF.a(1)=%g F.b(1)=%g\n",F.a(1),F.b(1));

        print_f_of_1(sin);
        print_f_of_1(cos);
        print_f_of_1(tan);
        print_f_of_1(erf);

	double x = 0;
	if(argc>1) x = atof(argv[1]);
	printf("command line argument = %g\n",x);

	fprintf(stdout,"hello\n");
	fprintf(stderr,"error\n");
	while(scanf("%lg",&x)!=EOF){
		printf("x = %lg\n",x);
	}
	
return 0;
}