
















/*
	definition of a block and print its size and adress.
*/
// #include <stdio.h>
// #include <gsl/gsl_block.h>

// int main(void){
// 	printf("Hello world\n");
// 	gsl_block * B = gsl_block_alloc(100);
// 	printf("length of block = %zu\n",B->size);
// 	printf("adress of block = %p\n",(*B).data);
// 	gsl_block_free(B);
// 	return 0;
// }

/*
	induces a out of bound vector error
*/
// #include <stdio.h>
// #include <gsl/gsl_vector.h>
// int
// main (void)
// {
//   int i;
//   gsl_vector * v = gsl_vector_alloc (3);
  
//   for (i = 0; i < 3; i++)
//     {
//       gsl_vector_set (v, i, 1.23 + i);
//     }
  
//   for (i = 0; i < 100; i++) /* OUT OF RANGE ERROR */
//     {
//       printf ("v_%d = %g\n", i, gsl_vector_get (v, i));
//     }

//   gsl_vector_free (v);
//   return 0;
// }

/*
	Print value of vector to file
*/
// #include <stdio.h>
// #include <gsl/gsl_vector.h>
// int main (void){
//   int i; 
//   gsl_vector * v = gsl_vector_alloc (100);
  
//   for (i = 0; i < 100; i++){
//       gsl_vector_set (v, i, 1.23 + i);
//     }

//   {  
//      FILE * f = fopen ("test.dat", "w");
//      gsl_vector_fprintf (f, v, "%6.5g");
//      fclose (f);
//   }

//   gsl_vector_free (v);
//   return 0;
// }

/*
	read back vector (only first ten elements) and prints
*/
// #include <stdio.h>
// #include <gsl/gsl_vector.h>

// int
// main (void)
// {
//   int i; 
//   gsl_vector * v = gsl_vector_alloc (10);

//   {  
//      FILE * f = fopen ("test.dat", "r");
//      gsl_vector_fscanf (f, v);
//      fclose (f);
//   }

//   for (i = 0; i < 10; i++)
//     {
//       printf ("%g\n", gsl_vector_get(v, i));
//     }

//   gsl_vector_free (v);
//   return 0;
// }


/*
	create matrix and reads it.. out of range error.
*/
// #include <stdio.h>
// #include <gsl/gsl_matrix.h>

// int
// main (void)
// {
//   int i, j; 
//   gsl_matrix * m = gsl_matrix_alloc (10, 3);
  
//   for (i = 0; i < 10; i++)
//     for (j = 0; j < 3; j++)
//       gsl_matrix_set (m, i, j, 0.23 + 100*i + j);
  
//   for (i = 0; i < 100; i++)  /* OUT OF RANGE ERROR */
//     for (j = 0; j < 3; j++)
//       printf ("m(%d,%d) = %g\n", i, j, 
//               gsl_matrix_get (m, i, j));

//   gsl_matrix_free (m);

//   return 0;
// }

/*
	vector view of matrices
*/
#include <math.h>
#include <stdio.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_blas.h>

int main (void){
  size_t i,j;
  gsl_matrix *m = gsl_matrix_alloc (10, 10);

  for (i = 0; i < 10; i++)
    for (j = 0; j < 10; j++)
      gsl_matrix_set (m, i, j, i + j); // sin (i) + cos (j));

  for (j = 0; j < 10; j++){
      gsl_vector_view column = gsl_matrix_column(m, j);
      double d;
      d = gsl_blas_dnrm2 (&column.vector);
      printf ("matrix column %zu, norm = %g\n", j, d);
  }

  gsl_matrix_free (m);

  return 0;
}
