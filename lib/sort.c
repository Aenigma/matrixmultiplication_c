#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include "sort.h"

static inline void swap(long int *pos1, long int *pos2)
{
	long int tmp;

	tmp = *pos1;
	*pos1 = *pos2;
	*pos2 = tmp;
}

static void bubble_sort(long int **mat, int d1, int d2)
{
	int size = d1 * d2;

	int i, j;

	for (i = 0; i < size; i++) {
		for (j = 0; j < size - 1; j++) {
			int p1_1 = j / d1;	
			int p1_2 = j % d1;

			int p2_1 = (j + 1) / d1;	
			int p2_2 = (j + 1) % d1;

			if (mat[p1_1][p1_2] > mat[p2_1][p2_2]) {
#ifdef DEBUG
				printf("swapping: %ld@(%d,%d) <-> %ld@(%d,%d)\n", mat[p1_1][p1_2], p1_1, p1_2, mat[p2_1][p2_2],p2_1, p2_2);
#endif
				swap(&mat[p1_1][p1_2], &mat[p2_1][p2_2]);
			}
		}
	}

#ifdef DEBUG
	for (i = 0; i < size; i++) {
		int p1_1 = i / d1;	
		int p1_2 = i % d1;

		printf("%ld@(%d,%d)\n", mat[p1_1][p1_2], p1_1, p1_2);
	}
#endif

}

void sort(long int **mat, int d1, int d2)
{
	bubble_sort(mat, d1, d2);
}
