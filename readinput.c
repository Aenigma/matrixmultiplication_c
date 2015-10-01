#include <stdio.h>
#include <stdlib.h>
#include "lib/matrixgen.h"

#define INPUT_FILE	"COSC450_P1_Data.txt"
#define OUTPUT_FILE	"COSC450_P1_Output.txt"

int main()
{
	/** we can now read the file */
	FILE *fin  = fopen(INPUT_FILE, "r");

	long int ***mat = NULL;

	int count = read_2_matrices(fin, &mat);

	printf("m1: \n");
	arr_rect_join(mat[0], 5, count/10, "", ", ", "\n");
	
	printf("m2: \n");
	arr_rect_join(mat[1], count/10, 5, "", ", ", "\n");
	
	return 0;
}
