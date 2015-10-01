#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void matrix_mult(long int **m1, long int **m2, long int ***result, int m1_d1, int m1_d2, int m2_d2)
{
	long int **res = (long int **) malloc(m1_d1 * sizeof(long int *));

	int d1_count = m1_d1;
	while(d1_count--) {
		res[d1_count] = (long int *) malloc(m2_d2 * sizeof(long int *));
	}

	int i, j, k;
	for (i = 0; i < m1_d1; i++) {
		for (j = 0; j < m2_d2; j++) {
			res[i][j] = 0;
			for (k = 0; k < m1_d2; k++) {
				res[i][j] += m1[i][k] * m2[k][j];
			}
		}
	}

	*result = res;
}
