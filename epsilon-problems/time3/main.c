/*rewrite (a>b!a:b) using if statement*/
#include <stdio.h>/* "" looks in all system directores. <> is system thing.*/
int main(){
	int f = 3;
	printf("This is your result: %i\n",f);
	int i = 0;
	int n = 3;
	if(i==1) printf("true\n");
	else printf("false\n");
	for(int i=0;n<2,i<10;i++,n++) printf("i = %i, n = %i\n",i,n);
	int c = ex_1();
	printf("return value of ex_1 is %i\n",c);
	ex_2();
	ex11();
	n=0;
	while (n<10){
		printf("The value of n is %i\n",++n);
		}
	printf("We broke out of the while-loop\n");
	int PRINTSTATEMENT = 0;
	do {
		printf("print this statement at least once\n");
	} while (PRINTSTATEMENT);
	for(int n=0; n<=10; n++){
		printf("Value n=%i in this loop.\n",n);
	}
	return 0;
}

int ex_1(){
	/*rewrite (a>b?a:b)*/
	int a = 0;
	int b = 5;
	if(a>b) return a;
	else return b;
	return (a>b?a:b);
}

int ex_2(){
	printf("Output from exercise 6: ");
	int i=1; printf(" %i",i++); printf("%i\n",++i);
	printf("Output from exercise 7: ");
	int j=1; printf("%i %i\n",j++,j++);	
	return 0;
}

int ex11(){
	if(0) printf("0 is true\n");
	else  printf("0 is false\n");
	if(7) printf("7 is true\n");
	else  printf("7 is false\n");
	return 0;
}

/*
cc math.o hello.o -o -lm math \\ to link hello to math.. not understood
cc time3.c | cc time3.c | ./a.out \\ compiles twice program, the runs it.
*/

/* lecture notes
make-file = a cookbook.
must start with tabulated sign.
benchmode: no user inputs.

grep command:
man complex | grep "\-lm"
*/
