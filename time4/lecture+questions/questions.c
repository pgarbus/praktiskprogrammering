// question 12
#include<stdio.h>
int i=2; /* file scope */
void f(){printf("i=%i\n",i);}
int main(){
	int i=1; /* function scope */
	{
		int i=0; /* block scope */
		printf("i=%i\n",i);
	}
	printf("i=%i\n",i);
	f();
	return 0; }

/*
#include <stdio.h>
quest10(){
	int a[5];

	printf("quest 10 = %i\n", a[3]);
}
int main(int argc, char const *argv[])
{
	quest10()
	return 0;
}
*/