#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lib/matrix.h"
#include "lib/sort.h"

#define INPUT_FILE	"COSC450_P1_Data.txt"
#define OUTPUT_FILE	"COSC450_P1_Output.txt"

int main()
{

	time_t t = time(0);

	/** we can now read the file */
	FILE *fin  = fopen(INPUT_FILE, "r");

	if(fin == NULL) {
		perror(INPUT_FILE);
		exit(-1);
	}

	long int ***mat = NULL;
	long int **mult_mat = NULL;

	int count = read_2_matrices(fin, &mat);

	FILE *fout  = fopen(OUTPUT_FILE, "a");
	
	fclose(fin);
	if(fout == NULL) {
		perror(OUTPUT_FILE);
		exit(-1);
	}

	printf("m1: \n");
	arr_rect_join(stdout, mat[0], 5, count/10, "", ", ", "\n");
	
	printf("m2: \n");
	arr_rect_join(stdout, mat[1], count/10, 5, "", ", ", "\n");

	matrix_mult(mat[0], mat[1], &mult_mat, 5, count/10, 5);
	printf("result: \n");
	arr_rect_join(stdout, mult_mat, 5, 5, "", ", ", "\n");

	fprintf(fout, "========== %s", ctime(&t));

	fprintf(fout, "Multiplication Result: \n");
	arr_rect_join(fout, mult_mat, 5, 5, "", ", ", "\n");


	sort(mult_mat, 5, 5);

	fprintf(stdout, "Sorted Multiplication Result: \n");
	arr_rect_join(stdout, mult_mat, 5, 5, "", ", ", "\n");

	fprintf(fout, "Sorted Multiplication Result: \n");
	arr_rect_join(fout, mult_mat, 5, 5, "", ", ", "\n");

	fprintf(fout, "==========\n\n");

	printf("\nResults appended to: %s \n", OUTPUT_FILE);
	fclose(fout);
	
	return 0;
}
