#include <stdio.h>

/**
 * This file defines io and splitting functions to obtain the matrix from file
 */

/**
 * Reads fin using a long int buffer. A pointer must be passed to the buffer
 * to resize it. The value of size_ptr is also updated according to the
 * reallocation of the buffer_ptr.
 */
extern int readldfile(FILE *fin, long int **buffer_ptr, int *size_ptr);

/**
 * Takes an array, its number of elements, a number to split with, and
 * populates it to the 
 *
 * arr   = an array
 * count = number of elements in array
 * quotient = number of elements to split with
 * split_arr_list_ptr = a pointer to a 2D array of arrays of `quotient` elements
 * 	split arrays with `count/quotient` elements in each array. The value
 * 	here can be a null pointer as it will be populated by the function.
 *
 * return = 0 if successful, else if not
 */
extern int split_arr(long int *arr, int count, int quotient, long int ***split_arr_list_ptr);

/**
 * Reads in a file and populats pointer with 2 2D matrices. The dimensions of
 * the matrix should be obtainable by the function's return value, the count
 * of values in the file.
 *
 * The first matrix should be a row_size by count/10 matrix
 * The second matrix should be an count/10 by row_size matrix
 *
 * fin = input file
 * row_size = number of elements in each row of the first matrix 
 * mat = a pointer to a 3D matrix of only 2 matrices that will be populated by
 *	 the file contents
 */
extern int read_2_matrices(FILE *fin, int row_size, long int ****mat);

/**
 * This function is able to display a rectangular 2D array. That is, a matrix.
 *
 * arr = 2d array
 * d1 = size of its first dimension
 * d2 = size of its second dimension
 * prefix = show before the output
 * delimiter = show between each element
 * suffic = shown after the output
 */
extern void arr_rect_join(FILE* dest, long int **arr, int d1, int d2, const char* prefix, const char* delimiter, const char* suffix);

extern void matrix_mult(long int **m1, long int **m2, long int ***result, int m1_d1, int m1_d2, int m2_d2);
