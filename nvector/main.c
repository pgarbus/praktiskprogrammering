#include "nvector.h"
#include "stdio.h"
#include "stdlib.h"

int main()
{
	// Main FUNC is appearently not needed...
	printf("Main.c is running just fine.\n");
	nvector* v = nvector_alloc(3);
	nvector* w = nvector_alloc(3);
	nvector_print("printing v before setting values = ",v);
	// free(v);
	// nvector_print("printing v = ",v);
	nvector_set(v,0,3);
	nvector_set(v,1,4);
	nvector_set(v,2,8);
	nvector_set(w,0,14);
	nvector_set(w,1,13);
	nvector_set(w,2,11);
	
	nvector_print("printing v after setting values = ",v);
	nvector_print("printing w after setting values = ",w);
	int index = 1;
	printf("(*v).data[%i] = %g\n", index, nvector_get(v,index));
	double dotproduct = nvector_dot_product(v,w);
	printf("dot product v and w = %g\n", dotproduct);
	int is_equal = nvector_equal(v,w);
	printf("vector v and w are equal (1) or not (0): %i\n",is_equal);

	nvector_print("printing v before adding w = ",v);
	nvector_add(v,w);
	nvector_print("printing v after adding w = ",v);
	
	nvector_sub(v,w);
	nvector_print("printing v after substracting w = ",v);
	
	nvector_scale(v,5);
	nvector_print("printing v after scaling with 5 = ",v);
	

	nvector_set_zero(v);
	nvector_set_zero(w);
	nvector_print("printing v after zeroing values = ",v);
	nvector_print("printing w after zeroing values = ",w);
	is_equal = nvector_equal(v,w);
	printf("vector v and w are equal (1) or not (0): %i\n",is_equal);

	return 0;
}