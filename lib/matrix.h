typedef struct {
	long **mat;
	int row;
	int column;
} matrix;

/**
 * @param m1 matrix to multiply
 * @param m2 matrix to multiply; will be modified
 */
extern matrix matrix_mult(matrix m1, matrix m2);

/**
 * Splits elements to half and creates an N*dim matrix and a dim*N matrix and
 * returns it.
 *
 * @param elements to split
 * @param dim divides by dim to get
 */
extern matrix* matrix_split(long elements[], int dim);

/**
 * creates a matrix from a single dimensional array
 */
extern matrix matrix_construct(long *elements, int size);

/**
 *
 */
extern void matrix_display(matrix mat, FILE* output);
