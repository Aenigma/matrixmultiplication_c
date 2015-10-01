#include "matrix.h"

static void arr_join(FILE *dest, long int *arr, int size, const char* prefix, const char* delimiter, const char* suffix);

static void arr_join(FILE *dest, long int *arr, int size, const char* prefix, const char* delimiter, const char* suffix)
{
	fprintf(dest, "%s", prefix);
	if(size >= 1) {
		int i;
		for (i = 0; i < size-1; i++) {
			fprintf(dest, "%ld%s", arr[i], delimiter);
		}
		fprintf(dest, "%ld", arr[i]);
	}
	fprintf(dest, "%s", suffix);
}

void arr_rect_join(FILE* dest, long int **arr, int d1, int d2, const char* prefix, const char* delimiter, const char* suffix)
{
	fprintf(dest, "%s", prefix);
	if(d1 >= 1) {
		int i;
		for (i = 0; i < d1-1; i++) {
			arr_join(dest, arr[i], d2, "[", delimiter, "]");
			fprintf(dest, "%s\n", delimiter);
		}
		arr_join(dest, arr[i], d2, "[", delimiter, "]");
	}

	fprintf(dest, "%s", suffix);
}
