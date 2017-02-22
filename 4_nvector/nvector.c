#include <stdio.h>
#include "nvector.h"
#include <math.h>
#include <stdlib.h>
#include <assert.h>

nvector* nvector_alloc(int n) {
	// allocates memory for size-n vector.
	nvector* v = malloc(sizeof(nvector));
	(*v).size = n;
	(*v).data = malloc(n*sizeof(double));
	if(v == NULL) fprintf(stderr, "Error in nvector_alloc\n");
	return v;
}
void nvector_print(char* s, nvector* v){
	printf("%s[", s);
	for(int i=0;i<(*v).size;i++){printf("%g, ",(*v).data[i]);}
	printf("\b\b]\n");
}
void nvector_free(nvector* v){
	free(v->data);
	free(v);
	v=NULL;
}
void nvector_set(nvector* v, int i, double value){
	// assert(0 <= i && i < (*v).size)
	assert(0<=i && v->size > i);
	(*v).data[i]=value;
}
double nvector_get(nvector* v, int i){
	assert(0<=i && (*v).size > i);
	return (*v).data[i];
}
double nvector_dot_product(nvector* v, nvector* w){
	assert(v->size == w->size);
	double result = 0;
	for(int i=0; i < v->size; i++){result += (*v).data[i]*(*w).data[i];}
	return result;
}
void nvector_set_zero(nvector* v){
	for(int i=0;(*v).size > i;i++){(*v).data[i]=0;}
}
int nvector_equal(nvector* v, nvector* w){
	int size = v->size;
	if (v->size != w->size) return 0;
	else {
		for(int i=0;i<size;i++){
			if((*v).data[i]!=(*w).data[i]){
				return 0;
			}
		}
	return 1;
	}
}
void nvector_add(nvector* v, nvector* w){
	assert(v->size == w->size);
	for(int i=0;i<v->size;i++){(*v).data[i]+=(*w).data[i];}
}
void nvector_sub(nvector* v, nvector* w){
	assert(v->size == w->size);
	for(int i=0;i<v->size;i++){(*v).data[i]-=(*w).data[i];}
}
void nvector_scale(nvector* v, double x){
	for(int i=0;i<v->size;i++){v->data[i]*=x;}
}