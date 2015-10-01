#include <stdio.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

matrix matrix_mult(matrix m1, matrix m2)
{
	assert(m1.row == m2.column || m1.column == m2.row);
	matrix result;		

	result.row = m1.row;
	result.column = m2.row;

	printf("m1.row = %d, m1.column = %d\n", m1.row, m1.column);
	printf("result.row = %d, result.column = %d\n", result.row, result.column);


	puts("mallocing");
	long **mat = (long **) malloc(sizeof(long *) * result.column);
	if(!mat) {
		fprintf(stderr, "Got an error using malloc; crashing!\n");
		exit(-1);
	}

	result.mat = mat;

	printf("(%d, %d)\n", result.row, result.column);

	int i;
	int j;

	for (i = 0; i < result.row; ++i) {
		for (j = 0; j < result.column; ++j) {
			printf("(%d, %d), ", i, j);
			mat[i][j] = 1;
		}
		printf("\n");
	}
	puts("made results");

	return result;
}

matrix* matrix_split(long elements[], int dim)
{
	return NULL;
}

matrix matrix_construct(long *elements, int size)
{
	matrix new_matrix;
	return new_matrix;
}

void matrix_display(matrix mat, FILE* output)
{
	puts("Matrix display called");
	int i, j;
	for (i = 0; i < mat.row; ++i) {
		for (j = 0; j < mat.column; j++) {
			long index = mat.mat[i][j];
			printf("%ld", index);
		}
	}
}

void generate_dyn_2d_arr(long*** arr, int row, int column)
{
	long **tmp = (long **) malloc(sizeof(long *) * row);
	int i;
	for (i = 0; i < row; ++i) tmp[i] = (long *) malloc(sizeof(long) * column);


}
