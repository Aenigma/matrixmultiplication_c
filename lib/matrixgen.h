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
