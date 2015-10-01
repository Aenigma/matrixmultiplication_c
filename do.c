#include <stdio.h>
#include <stdlib.h>
#include "lib/matrix.h"

int main()
{
	matrix m1, m2;

	{
		int row = 20;
		int column = 20;

		m1.mat = (long **) malloc(sizeof(long *) * row);
		m2.mat = (long **) malloc(sizeof(long *) * row);

		int i;
		for (i = 0; i < column; ++i) {
			m1.mat[i] = (long *) malloc(sizeof(long) * column);
			m2.mat[i] = (long *) malloc(sizeof(long) * column);
		}

		m1.row = m2.row = row;
		m1.column= m2.column = column;
	}

	matrix result = matrix_mult(m1,m2);
	matrix_display(result, stdout);

	return 0;
}
