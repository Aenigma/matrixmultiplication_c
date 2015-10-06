#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "lib/matrix.h"
#include "lib/sort.h"

#define ROW 5

#define DEFAULT_INPUT_FILE	"COSC450_P1_Data.txt"
#define DEFAULT_OUTPUT_FILE	"COSC450_P1_Output.txt"

static void write_matrix(FILE* dest, const char *label, long int **matrix, int d1, int d2)
{
	fprintf(dest, "%s: \n", label);
	arr_rect_join(dest, matrix, d1, d2, "", ", ", "\n\n");
}

static void compute_matrices(const char *input_file, const char *output_file)
{
	/** we can now read the file */
	FILE *fin  = fopen(input_file, "r");

	if(fin == NULL) {
		perror(input_file);
		exit(-1);
	}

	long int ***mat = NULL;
	long int **mult_mat = NULL;

	int count = read_2_matrices(fin, ROW, &mat);

	int column = count / ROW / 2;

	FILE *fout;
	
	fclose(fin);

	fout = fopen(output_file, "w");
	if(fout == NULL) {
		perror(output_file);
		exit(-1);
	}

	write_matrix(stdout, "Matrix 1", mat[0], ROW, column);
	write_matrix(fout, "Matrix 1", mat[0], ROW, column);

	write_matrix(stdout, "Matrix 2", mat[1], column, ROW);
	write_matrix(fout, "Matrix 2", mat[1], column, ROW);

	matrix_mult(mat[0], mat[1], &mult_mat, ROW, column, ROW);

	write_matrix(stdout, "Multiplication Result", mult_mat, ROW, ROW);
	write_matrix(fout, "Multiplication Result", mult_mat, ROW, ROW);

	sort(mult_mat, ROW, ROW);

	write_matrix(stdout, "Sorted Multiplication Result", mult_mat, ROW, ROW);
	write_matrix(fout, "Sorted Multiplication Result", mult_mat, ROW, ROW);

	fclose(fout);
	printf("Results written to: %s \n", output_file);
}

static void print_help(int err)
{
	puts("-i inputfile\n"
			"\tif it does not exist, defaults to "
			DEFAULT_INPUT_FILE);
	puts("-o outputfile\n"
			"\tif it does not exist, defaults to "
			DEFAULT_OUTPUT_FILE);
	exit(err);
}

int main(int argc, char **argv)
{
	int opt;

	const char* input_file = DEFAULT_INPUT_FILE;
	const char* output_file = DEFAULT_OUTPUT_FILE;

	while((opt = getopt(argc, argv, "i:o:h")) != -1) {
		switch(opt) {
			case 'i':
				input_file = optarg;
				break;
			case 'o':
				output_file= optarg;
				break;
			case 'h':
				print_help(0);
			default:
				print_help(-1);
		}
	}
	
	compute_matrices(input_file, output_file);
	
	return 0;
}
