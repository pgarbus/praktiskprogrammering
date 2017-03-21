#include"stdio.h"
#include"komplex.h"
#define TINY 1e-6

void f1(int i){i=0;}
void f2(int* i){*i=0;}
void f3(int* i){i=NULL;}
void f4(int **i){*i=NULL;}

int main(){
	{
		printf("Question 6\n");
		printf("variable passed in, only a copy.");
		int i=1; f1(i); printf("i=%i\n",i);
		printf("Pointer passed in, change 1-->0 takes effect.");
		i=1; f2(&i); printf("i=%i\n",i);
		printf("pointer passed in, i becomes the NULL pointer.");
		i=1; f3(&i); printf("i=%i\n",i);
		printf("In fact only the value of the pointer is sent " 
			"to the function and not the pointer itself.\n the "
			"function should be void f4(int **p){*p = NULL;}\n and "
			"calling it with the address &-operator like f4(&&p).\n");
		int *p = &i; f4(&p); 
		if (i == NULL) printf("i was a NULL pointer!\n"); 
		else printf("i = %i was >>NOT<< a NULL pointer\n",*&i);
		printf("Somehow this is not true for my compiler...\n");
	}

	printf("\nEXERCISE KOMPLEX:");
	komplex a = {1,2}, b = {3,4};

	printf("\ntesting komplex_add...\n");
	komplex r = komplex_add(&a,&b);
	komplex_print("komplex_add",a);
	komplex_print("komplex_add",b);
	komplex R = {4,6};
	komplex_print("a=",a);
	komplex_print("b=",b);
	komplex_print("a+b should be  ", R);
	komplex_print("a+b actually is", r);

// /* the following is optional */

// 	if( komplex_equal(R,r,TINY,TINY) )
// 		printf("test 'add' passed :) \n");
// 	else
// 		printf("test 'add' failed: debug me, please... \n");
	return 0;
}