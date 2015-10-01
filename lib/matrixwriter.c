#include "matrix.h"

static void arr_join(long int *arr, int size, const char* prefix, const char* delimiter, const char* suffix);

static void arr_join(long int *arr, int size, const char* prefix, const char* delimiter, const char* suffix)
{
	printf("%s", prefix);
	if(size >= 1) {
		int i;
		for (i = 0; i < size-1; i++) {
			printf("%ld%s", arr[i], delimiter);
		}
		printf("%ld", arr[i]);
	}
	printf("%s", suffix);
}

void arr_rect_join(long int **arr, int d1, int d2, const char* prefix, const char* delimiter, const char* suffix)
{
	printf("%s", prefix);
	if(d1 >= 1) {
		int i;
		for (i = 0; i < d1-1; i++) {
			arr_join(arr[i], d2, "[", delimiter, "]");
			puts(delimiter);
		}
		arr_join(arr[i], d2, "[", delimiter, "]");
	}

	printf("%s", suffix);
}
