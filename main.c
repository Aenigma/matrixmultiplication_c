#include <stdio.h>
#include <stdlib.h>
#include "lib/matrix.h"

#define INPUT_FILE	"COSC450_P1_Data.txt"
#define OUTPUT_FILE	"COSC450_P1_Output.txt"

int main()
{
	/** we can now read the file */
	FILE *fin  = fopen(INPUT_FILE, "r");

	long int ***mat = NULL;
	long int **mult_mat = NULL;

	int count = read_2_matrices(fin, &mat);

	printf("m1: \n");
	arr_rect_join(mat[0], 5, count/10, "", ", ", "\n");
	
	printf("m2: \n");
	arr_rect_join(mat[1], count/10, 5, "", ", ", "\n");

	matrix_mult(mat[0], mat[1], &mult_mat, 5, count/10, 5);
	printf("result: \n");
	arr_rect_join(mult_mat, 5, 5, "", ", ", "\n");
	printf("printed");
	
	return 0;
}
