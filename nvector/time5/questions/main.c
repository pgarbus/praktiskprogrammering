#include <stdio.h>
	int main(){
	struct vector {double x,y,z;};
	struct vector v = {1,2,3};
	struct vector x = {1,2,3};
	struct vector a = [1,2,3];
	struct vector u = {.x=1,.y=2,.z=3};
	struct vector w = {.z=3,.y=2,.x=1};
	vector y;
	typedef struct vector vector;
	vector z;
	return 0;
}
