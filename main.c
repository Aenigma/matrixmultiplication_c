#include <stdio.h>
#include <stdlib.h>
#include "lib/matrix.h"
#include "lib/sort.h"

#define ROW 5

#define INPUT_FILE	"COSC450_P1_Data.txt"
#define OUTPUT_FILE	"COSC450_P1_Output.txt"

static void write_matrix(FILE* dest, const char *label, long int **matrix, int d1, int d2)
{
	fprintf(dest, "%s: \n", label);
	arr_rect_join(dest, matrix, d1, d2, "", ", ", "\n\n");
}

int main()
{

	/** we can now read the file */
	FILE *fin  = fopen(INPUT_FILE, "r");

	if(fin == NULL) {
		perror(INPUT_FILE);
		exit(-1);
	}

	long int ***mat = NULL;
	long int **mult_mat = NULL;

	int count = read_2_matrices(fin, ROW, &mat);

	FILE *fout;
	
	fclose(fin);

	fout = fopen(OUTPUT_FILE, "w");
	if(fout == NULL) {
		perror(OUTPUT_FILE);
		exit(-1);
	}

	write_matrix(stdout, "Matrix 1", mat[0], ROW, count/10);
	write_matrix(fout, "Matrix 1", mat[0], ROW, count/10);

	write_matrix(stdout, "Matrix 2", mat[1], count/10, ROW);
	write_matrix(fout, "Matrix 2", mat[1], count/10, ROW);

	matrix_mult(mat[0], mat[1], &mult_mat, ROW, count/10, ROW);

	write_matrix(stdout, "Multiplication Result", mult_mat, ROW, ROW);
	write_matrix(fout, "Multiplication Result", mult_mat, ROW, ROW);

	sort(mult_mat, ROW, ROW);

	write_matrix(stdout, "Sorted Multiplication Result", mult_mat, ROW, ROW);
	write_matrix(fout, "Sorted Multiplication Result", mult_mat, ROW, ROW);

	fclose(fout);
	printf("\nResults written to: %s \n", OUTPUT_FILE);
	
	return 0;
}
