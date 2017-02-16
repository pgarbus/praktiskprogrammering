#include <stdio.h>
#ifndef HAVE_NVECTOR_H // for multiple includes
typedef struct {int size; double* data;} nvector;

nvector* nvector_alloc(int n) {
	// allocates memory for size-n vector.
}