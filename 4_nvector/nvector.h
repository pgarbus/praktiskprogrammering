#ifndef HAVE_NVECTOR_H
typedef struct {int size; double* data;} nvector;
nvector* nvector_alloc(int n);
void nvector_free(nvector* v);
void nvector_set(nvector* v, int n, double value);
double nvector_get(nvector* v, int n);
double nvector_dot_product(nvector* v, nvector* w);
void nvector_print(char* s, nvector* v);
void nvector_set_zero(nvector* v);
int nvector_equal(nvector* v, nvector* w);
void nvector_add(nvector* v, nvector* w);
void nvector_sub(nvector* v, nvector* w);
void nvector_scale(nvector* v, double x);
#define HAVE_NVECTOR_H
#endif
